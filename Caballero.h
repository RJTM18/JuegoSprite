#pragma once
#include "Sprite.h"

class Caballero : public Sprite
{
private:
	Direccion direccion;   // ultima direccion hacia donde mira
	bool lanzando;
	int cansancio; //0 a 5

public:
	//Sprite(int x, int y, int ancho, int alto, int filas, int columnas)
	Caballero(int x, int y) : Sprite(x, y, 126, 126, 4, 5)
	{
		velocidad = 20;
		direccion = Derecha;
		lanzando = false;
		cansancio = 0;
	}

	Direccion getDireccion() { return direccion; }
	bool estaLanzando() { return lanzando; }

	int getCansancio() { return cansancio; }

	//HAMP Explica: la barra espaciadora activa el lanzamiento: muestra los cuadros 2 (fuego en la mano), 3 (lo lanza) 
	void lanzar()
	{
		if (cansancio >= 5) {
			lanzando = false;
			cansancio = 5;
		}

		if (lanzando) return;
		lanzando = true;
		indiceX = 1;
		
		cansancio++;
	}

	void descanso(Direccion tecla) {
		cansancio--;

		if (cansancio < 0) cansancio = 0;
	}

	void mover(Direccion tecla, int limiteAncho, int limiteAlto) override
	{
		//HAMP Explica: PASO 1 - si hay flecha, dx y dy dicen hacia donde ir y se avanza velocidad pixeles
		if (tecla != Ninguno)
		{
			direccion = tecla;
			dx = 0;
			dy = 0;

			if (tecla == Arriba) dy = -1;
			if (tecla == Abajo) dy = 1;
			if (tecla == Izquierda) dx = -1;
			if (tecla == Derecha) dx = 1;

			x += dx * velocidad;
			y += dy * velocidad;

			//HAMP Explica: PASO 2 - no salir del panel
			if (x < 0) x = 0;
			if (y < 0) y = 0;
			if (x > limiteAncho - ancho) x = limiteAncho - ancho;
			if (y > limiteAlto - alto) y = limiteAlto - alto;
		}

		//HAMP Explica: PASO 3 - la direccion elige la fila de la hoja
		if (direccion == Arriba) indiceY = 0;
		if (direccion == Abajo) indiceY = 1;
		if (direccion == Izquierda) indiceY = 2;
		if (direccion == Derecha) indiceY = 3;

		//HAMP Explica: PASO 4 - la columna depende de lo que hace: lanzar (2, 3 y 4: solo ahi sale el fuego), caminar (alterna 1 y 4, sin fuego) o estar quieto (0)
		if (lanzando)
		{
			indiceX++;//1->2->3->4
			if (indiceX > 4)
			{
				indiceX = 0;
				lanzando = false;
			}
		}
		else if (tecla != Ninguno)
		{
			if (indiceX == 1) indiceX = 4;
			else indiceX = 1;
		}
		else
		{
			indiceX = 0;
		}
	}
};
