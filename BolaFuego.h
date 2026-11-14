#pragma once
#include "Sprite.h"

class BolaFuego : public Sprite
{
private:
	float rotacion;   // giro para que apunte hacia donde va
	bool explotando;

public:
	BolaFuego(int centroX, int centroY, Direccion direccion) : Sprite(centroX - 44, centroY - 44, 88, 88, 4, 5)
	{
		velocidad = 35;
		indiceX = 1;
		indiceY = 0;
		explotando = false;

		//HAMP Explica: cada direccion tiene su dx, dy y su giro
		if (direccion == Derecha) { dx = 1; rotacion = -150; }
		if (direccion == Abajo) { dy = 1; rotacion = -60; }
		if (direccion == Izquierda) { dx = -1; rotacion = 30; }
		if (direccion == Arriba) { dy = -1; rotacion = 120; }
	}

	bool estaExplotando() { return explotando; }

	//HAMP Explica: al chocar se muestra el cuadro 4 (explosion)
	void explotar()
	{
		explotando = true;
		indiceX = 4;
	}

	//HAMP Explica: termina cuando acaba la explosion o cuando sale de la pantalla
	bool terminada(int limiteAncho, int limiteAlto)
	{
		if (explotando) return indiceX > 4;
		return x < -ancho || y < -alto || x > limiteAncho || y > limiteAlto;
	}

	void mover(Direccion tecla, int limiteAncho, int limiteAlto) override
	{
		//HAMP Explica: explotando no avanza, solo pasa al siguiente cuadro
		if (explotando)
		{
			indiceX++;
			return;
		}

		//HAMP Explica: en vuelo avanza velocidad pixeles hacia su direccion
		x += dx * velocidad;
		y += dy * velocidad;

		//HAMP Explica: cuadros de vuelo 1, 2, 3 y vuelve a 1
		indiceX++;
		if (indiceX > 3) indiceX = 1;
	}

	void dibujarBola(Graphics^ g, Bitmap^ imagen)
	{
		//HAMP Explica: la explosion se dibuja normal, sin giro
		if (explotando)
		{
			dibujar(g, imagen);
			return;
		}

		int anchoCelda = imagen->Width / columnas;
		int altoCelda = imagen->Height / filas;
		Rectangle origen = Rectangle(indiceX * anchoCelda, indiceY * altoCelda, anchoCelda, altoCelda);

		//HAMP Explica: se mueve el origen al centro de la bola, se gira, se pinta y se deshace el giro
		g->TranslateTransform((float)(x + ancho / 2), (float)(y + alto / 2));
		g->RotateTransform(rotacion);
		g->DrawImage(imagen, Rectangle(-ancho / 2, -alto / 2, ancho, alto), origen, GraphicsUnit::Pixel);
		g->ResetTransform();
	}
};
