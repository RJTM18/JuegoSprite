#pragma once
#include "Sprite.h"
#include <cstdlib>

class Enemigo : public Sprite
{
private:
	bool golpeado;
	int ticksGolpe;   // ticks que lleva golpeado

public:
	//Sprite(int x, int y, int ancho, int alto, int filas, int columnas)
	Enemigo(int x, int y) : Sprite(x, y, 126, 126, 4, 5)
	{
		//HAMP Explica: velocidad al azar entre 5 y 9, y la moneda (rand() % 2) decide si sube o baja
		velocidad = rand() % 5 + 5;
		dy = 1; // HAMP Explica: empieza bajando
		if (rand() % 2 == 0) dy = -1;
		indiceX = 0;
		golpeado = false;
		ticksGolpe = 0;
	}

	bool estaGolpeado() { return golpeado; }

	//HAMP Explica: al recibir la bola se activa el golpe y empieza en el cuadro 1
	void golpear()
	{
		golpeado = true;
		ticksGolpe = 0;
		indiceX = 1;
	}

	void mover(Direccion tecla, int limiteAncho, int limiteAlto) override
	{
		//HAMP Explica: golpeado no se mueve: cada 3 ticks pasa al siguiente cuadro del impacto (1, 2, 3) y despues se borra
		if (golpeado)
		{
			ticksGolpe++;
			if (ticksGolpe % 3 == 0) indiceX++; //1->2->3
			return;
		}

		//HAMP Explica: solo se mueve en vertical
		y += dy * velocidad;

		//HAMP Explica: al llegar arriba o abajo cambia de sentido (rebota)
		if (y < 0)
		{
			y = 0;
			dy = 1;
		}
		if (y > limiteAlto - alto)
		{
			y = limiteAlto - alto;
			dy = -1;
		}

		//HAMP Explica: baja = fila 1 (de frente), sube = fila 0 (de espaldas)
		if (dy == 1) indiceY = 1;
		else indiceY = 0;

		//HAMP Explica: camina alternando los cuadros 0 y 4 (un pie y el otro): cambia de pie cada 20 pixeles recorridos, asi se alcanza a ver; los cuadros 1, 2 y 3 son del impacto
		if ((y / 20) % 2 == 0) indiceX = 0;
		else indiceX = 4;
	}
};
