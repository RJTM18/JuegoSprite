#pragma once
using namespace System::Drawing;

enum Direccion { Abajo, Izquierda, Derecha, Arriba, BotonC, Ninguno };

class Sprite
{
protected:
	int x, y;                  // posicion en el panel (Panel)
	int dx, dy;                // hacia donde se mueve (-1, 0 o 1)
	int ancho, alto;           // tamano con el que se dibuja
	int filas, columnas;       // cuadricula de la hoja de sprites
	int indiceX, indiceY;      // cuadro actual: columna y fila
	int velocidad;             // pixeles que avanza por tick

public:
	Sprite(int x, int y, int ancho, int alto, int filas, int columnas)
	{
		this->x = x;
		this->y = y;
		this->ancho = ancho;
		this->alto = alto;
		this->filas = filas;
		this->columnas = columnas;
		dx = 0;
		dy = 0;
		indiceX = 0;
		indiceY = 0;
		velocidad = 0;
	}

	virtual ~Sprite() {}

	// Cada hijo define como se mueve
	virtual void mover(Direccion tecla, int limiteAncho, int limiteAlto) = 0;

	//Bitmap^ imagen => Sprite que es un conjunto de Frames (cuadros) que se recortan y se dibujan en el panel
	//Graphics^ g => lienzo donde se dibuja el sprite
	void dibujar(Graphics^ g, Bitmap^ imagen)
	{
		//HAMP Explica: tamano de un cuadro = imagen / cuadricula
		int anchoCelda = imagen->Width / columnas;
		int altoCelda = imagen->Height / filas;

		//HAMP Explica: origen = cuadro que se recorta, destino = donde se pinta
		Rectangle origen = Rectangle(indiceX * anchoCelda, indiceY * altoCelda, anchoCelda, altoCelda);
		Rectangle destino = Rectangle(x, y, ancho, alto);
		g->DrawImage(imagen, destino, origen, GraphicsUnit::Pixel);
	}

	//HAMP Explica: rectangulo de colision: empieza a 1/5 del dibujo y mide 3/5 de ancho y de alto, asi no cuenta el aire alrededor del personaje
	Rectangle getRectangle()
	{
		return Rectangle(x + ancho / 5, y + alto / 5, ancho * 3 / 5, alto * 3 / 5);
	}

	//HAMP Explica: TEMPORAL (solo para entender): dibuja el rectangulo de colision como un borde rojo. Luego se retira
	void dibujarRectangulo(Graphics^ g)
	{
		g->DrawRectangle(Pens::Red, getRectangle());
	}

	int getX() { return x; }
	int getY() { return y; }
	int getIndiceX() { return indiceX; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
};
