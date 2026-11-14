#pragma once
#include <vector>
#include "Caballero.h"
#include "Enemigo.h"
#include "BolaFuego.h"
using namespace std;

class Juego
{
private:
	Caballero* caballero;
	vector<Enemigo*> enemigos;
	vector<BolaFuego*> bolas;
	int eliminados; //Contador de numero de enemigos eliminados
	int cantidad = 5;

	//HAMP Explica: crea 5 enemigos en la mitad derecha del panel
	void crearEnemigos(int ancho, int alto)
	{
		for (int i = 0; i < cantidad; i++)
		{
			int x = ancho / 2 + rand() % (ancho / 2 - 150);
			int y = rand() % (alto - 150);
			enemigos.push_back(new Enemigo(x, y));
		}
	}

public:
	Juego(int ancho, int alto)
	{
		caballero = new Caballero(60, alto / 2);
		eliminados = 0;
		crearEnemigos(ancho, alto);
	}

	~Juego()
	{
		delete caballero;
		for (int i = 0; i < enemigos.size(); i++) delete enemigos[i];
		for (int i = 0; i < bolas.size(); i++) delete bolas[i];
	}

	int getEliminados() { return eliminados; }
	int getCantidadEnemigos() { return cantidad; }

	void lanzarBola() { caballero->lanzar(); }

	void CaballeroDescanso(Direccion tecla) {
		if (tecla == BotonC) { caballero->descanso(tecla); }
	}

	int getCaballeroCansancio() { return caballero->getCansancio(); }


	void mover(Direccion tecla, int ancho, int alto)
	{
		caballero->mover(tecla, ancho, alto);

		//HAMP Explica: cuando el caballero llega al cuadro 3 de lanzar, nace la bola delante de el
		if (caballero->estaLanzando() && caballero->getIndiceX() == 3)
		{
			int bolaX = caballero->getX() + 63;
			int bolaY = caballero->getY() + 63;

			Direccion direccion = caballero->getDireccion();

			if (direccion == Derecha) bolaX += 60;
			if (direccion == Izquierda) bolaX -= 60;
			if (direccion == Abajo) bolaY += 60;
			if (direccion == Arriba) bolaY -= 60;

			bolas.push_back(new BolaFuego(bolaX, bolaY, direccion));
		}

		//HAMP Explica: se mueve cada enemigo y se borra el que ya termino su golpe
		for (int i = 0; i < enemigos.size(); i++)
		{
			enemigos[i]->mover(Ninguno, ancho, alto);
			if (enemigos[i]->estaGolpeado() && enemigos[i]->getIndiceX() > 3)
			{
				delete enemigos[i];
				enemigos.erase(enemigos.begin() + i);
				i--;
			}
		}

		//HAMP Explica: se mueve cada bola y se borra la que ya termino
		for (int i = 0; i < bolas.size(); i++)
		{
			bolas[i]->mover(Ninguno, ancho, alto);
			if (bolas[i]->terminada(ancho, alto))
			{
				delete bolas[i];
				bolas.erase(bolas.begin() + i);
				i--;
			}
		}

		colisionBolaEnemigo();

		//HAMP Explica: si no quedan enemigos, aparece otra tanda
		if (enemigos.size() == 0) crearEnemigos(ancho, alto);
	}

	//HAMP Explica: cada bola en vuelo se compara con cada enemigo; si se intersectan, el enemigo reacciona y la bola explota
	void colisionBolaEnemigo()
	{
		for (int i = 0; i < bolas.size(); i++)
		{
			if (bolas[i]->estaExplotando()) continue;

			for (int j = 0; j < enemigos.size(); j++)
			{
				if (enemigos[j]->estaGolpeado()) continue;

				if (bolas[i]->getRectangle().IntersectsWith(enemigos[j]->getRectangle()))
				{
					enemigos[j]->golpear();
					bolas[i]->explotar();
					eliminados++;//contador eliminados se incrementa al eliminar un enemigo
					break;
				}
			}
		}
	}

	//HAMP Explica: orden de dibujo = enemigos, caballero y bolas (lo ultimo se ve encima). Cada personaje usa su hoja
	void dibujar(Graphics^ g, Bitmap^ imgCaballero, Bitmap^ imgEnemigo, Bitmap^ fuego)
	{
		for (int i = 0; i < enemigos.size(); i++)
		{
			enemigos[i]->dibujar(g, imgEnemigo);
		}

		caballero->dibujar(g, imgCaballero);

		for (int i = 0; i < bolas.size(); i++)
		{
			bolas[i]->dibujarBola(g, fuego);
		}

		////HAMP Explica: TEMPORAL: se dibujan los rectangulos de colision de enemigos, caballero y bolas (retirar despues)
		//for (int i = 0; i < enemigos.size(); i++) enemigos[i]->dibujarRectangulo(g);
		//caballero->dibujarRectangulo(g);
		//for (int i = 0; i < bolas.size(); i++) bolas[i]->dibujarRectangulo(g);
	}
};
