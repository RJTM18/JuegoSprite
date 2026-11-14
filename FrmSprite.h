#pragma once
#include "Juego.h"
#include <string>

namespace JuegoSprite {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class FrmSprite : public System::Windows::Forms::Form
	{
	public:
		FrmSprite(void)
		{
			InitializeComponent();
			juego = nullptr;
		}

	protected:
		~FrmSprite()
		{
			if (components) delete components;
			if (juego != nullptr) delete juego;
		}

	private:
		// Controles del disenador
		System::Windows::Forms::Panel^ pnlSprite;
		System::Windows::Forms::Panel^ pnlInfo;
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Label^ lblEliminados;
		System::Windows::Forms::Label^ lblAyuda1;
		System::Windows::Forms::Label^ lblAyuda2;
		System::Windows::Forms::Timer^ timer1;
		System::ComponentModel::IContainer^ components;

		// Hojas de sprites y fondo
		Bitmap^ caballero;
		Bitmap^ enemigo;
		Bitmap^ fuego;
		Bitmap^ fondo;

		// Juego y flecha pulsada
		Juego* juego;

		int restantes = 10 - juego->getEliminados();

	private: System::Windows::Forms::Label^ lblCantCansancio;



	private: System::Windows::Forms::Label^ lblCansancio;
	private: System::Windows::Forms::Label^ lblCantRestantes;


	private: System::Windows::Forms::Label^ lblRestantes;

		   Direccion teclaPresionada;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pnlSprite = (gcnew System::Windows::Forms::Panel());
			this->pnlInfo = (gcnew System::Windows::Forms::Panel());
			this->lblCantRestantes = (gcnew System::Windows::Forms::Label());
			this->lblRestantes = (gcnew System::Windows::Forms::Label());
			this->lblCantCansancio = (gcnew System::Windows::Forms::Label());
			this->lblCansancio = (gcnew System::Windows::Forms::Label());
			this->lblAyuda2 = (gcnew System::Windows::Forms::Label());
			this->lblAyuda1 = (gcnew System::Windows::Forms::Label());
			this->lblEliminados = (gcnew System::Windows::Forms::Label());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnlInfo->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlSprite
			// 
			this->pnlSprite->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlSprite->Location = System::Drawing::Point(0, 0);
			this->pnlSprite->Name = L"pnlSprite";
			this->pnlSprite->Size = System::Drawing::Size(820, 614);
			this->pnlSprite->TabIndex = 0;
			this->pnlSprite->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmSprite::pnlSprite_Paint);
			// 
			// pnlInfo
			// 
			this->pnlInfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->pnlInfo->Controls->Add(this->lblCantRestantes);
			this->pnlInfo->Controls->Add(this->lblRestantes);
			this->pnlInfo->Controls->Add(this->lblCantCansancio);
			this->pnlInfo->Controls->Add(this->lblCansancio);
			this->pnlInfo->Controls->Add(this->lblAyuda2);
			this->pnlInfo->Controls->Add(this->lblAyuda1);
			this->pnlInfo->Controls->Add(this->lblEliminados);
			this->pnlInfo->Controls->Add(this->lblTitulo);
			this->pnlInfo->Dock = System::Windows::Forms::DockStyle::Right;
			this->pnlInfo->Location = System::Drawing::Point(820, 0);
			this->pnlInfo->Name = L"pnlInfo";
			this->pnlInfo->Size = System::Drawing::Size(240, 614);
			this->pnlInfo->TabIndex = 1;
			// 
			// lblCantRestantes
			// 
			this->lblCantRestantes->Font = (gcnew System::Drawing::Font(L"Arial", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCantRestantes->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->lblCantRestantes->Location = System::Drawing::Point(0, 427);
			this->lblCantRestantes->Name = L"lblCantRestantes";
			this->lblCantRestantes->Size = System::Drawing::Size(240, 55);
			this->lblCantRestantes->TabIndex = 7;
			this->lblCantRestantes->Text = L"10";
			this->lblCantRestantes->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblRestantes
			// 
			this->lblRestantes->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
			this->lblRestantes->ForeColor = System::Drawing::Color::White;
			this->lblRestantes->Location = System::Drawing::Point(-2, 387);
			this->lblRestantes->Name = L"lblRestantes";
			this->lblRestantes->Size = System::Drawing::Size(240, 40);
			this->lblRestantes->TabIndex = 6;
			this->lblRestantes->Text = L"RESTANTES";
			this->lblRestantes->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblCantCansancio
			// 
			this->lblCantCansancio->Font = (gcnew System::Drawing::Font(L"Arial", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCantCansancio->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->lblCantCansancio->Location = System::Drawing::Point(0, 310);
			this->lblCantCansancio->Name = L"lblCantCansancio";
			this->lblCantCansancio->Size = System::Drawing::Size(240, 55);
			this->lblCantCansancio->TabIndex = 5;
			this->lblCantCansancio->Text = L"0";
			this->lblCantCansancio->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblCansancio
			// 
			this->lblCansancio->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
			this->lblCansancio->ForeColor = System::Drawing::Color::White;
			this->lblCansancio->Location = System::Drawing::Point(0, 279);
			this->lblCansancio->Name = L"lblCansancio";
			this->lblCansancio->Size = System::Drawing::Size(240, 40);
			this->lblCansancio->TabIndex = 4;
			this->lblCansancio->Text = L"CANSANCIO";
			this->lblCansancio->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblAyuda2
			// 
			this->lblAyuda2->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->lblAyuda2->ForeColor = System::Drawing::Color::White;
			this->lblAyuda2->Location = System::Drawing::Point(0, 227);
			this->lblAyuda2->Name = L"lblAyuda2";
			this->lblAyuda2->Size = System::Drawing::Size(240, 25);
			this->lblAyuda2->TabIndex = 3;
			this->lblAyuda2->Text = L"Espacio: bola de fuego";
			this->lblAyuda2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblAyuda1
			// 
			this->lblAyuda1->Font = (gcnew System::Drawing::Font(L"Arial", 11));
			this->lblAyuda1->ForeColor = System::Drawing::Color::White;
			this->lblAyuda1->Location = System::Drawing::Point(0, 197);
			this->lblAyuda1->Name = L"lblAyuda1";
			this->lblAyuda1->Size = System::Drawing::Size(240, 25);
			this->lblAyuda1->TabIndex = 2;
			this->lblAyuda1->Text = L"Flechas: mover";
			this->lblAyuda1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblEliminados
			// 
			this->lblEliminados->Font = (gcnew System::Drawing::Font(L"Arial", 48, System::Drawing::FontStyle::Bold));
			this->lblEliminados->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->lblEliminados->Location = System::Drawing::Point(0, 90);
			this->lblEliminados->Name = L"lblEliminados";
			this->lblEliminados->Size = System::Drawing::Size(240, 90);
			this->lblEliminados->TabIndex = 1;
			this->lblEliminados->Text = L"0";
			this->lblEliminados->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblTitulo
			// 
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
			this->lblTitulo->ForeColor = System::Drawing::Color::White;
			this->lblTitulo->Location = System::Drawing::Point(0, 40);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(240, 40);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"ELIMINADOS";
			this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmSprite::timer1_Tick);
			// 
			// FrmSprite
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1060, 614);
			this->Controls->Add(this->pnlSprite);
			this->Controls->Add(this->pnlInfo);
			this->KeyPreview = true;
			this->Name = L"FrmSprite";
			this->Text = L"Caballero y enemigos";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FrmSprite::FrmSprite_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmSprite::FrmSprite_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmSprite::FrmSprite_KeyUp);
			this->pnlInfo->ResumeLayout(false);
			this->ResumeLayout(false);

		}

		


#pragma endregion


		Bitmap^ cargarImagen(String^ nombre)
		{
			String^ ruta = Path::Combine(Application::StartupPath, nombre);
			if (!File::Exists(ruta)) ruta = nombre;
			return gcnew Bitmap(ruta);
		}

		//HAMP Explica: al abrir el formulario se cargan todas las imagenes
		System::Void FrmSprite_Load(System::Object^ sender, System::EventArgs^ e)
		{
			caballero = cargarImagen("cabellero_new.png");
			enemigo = cargarImagen("enemigo_new.png");
			fuego = cargarImagen("fuego_new.png");
			fondo = cargarImagen("fondo_paisaje_01.png");
			teclaPresionada = Ninguno;
		}

		//HAMP Explica: cada tick = mover todo y luego dibujar todo
		System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
		{
			int ancho = pnlSprite->Width;
			int alto = pnlSprite->Height;
			if (ancho <= 0 || alto <= 0) return;

			if (juego == nullptr) juego = new Juego(ancho, alto);

			juego->mover(teclaPresionada, ancho, alto);

			//HAMP Explica: buffer = se dibuja todo en una imagen oculta y se muestra completa (sin parpadeo)
			Graphics^ canvas = pnlSprite->CreateGraphics();

			BufferedGraphics^ buffer = BufferedGraphicsManager::Current->Allocate(canvas, pnlSprite->ClientRectangle);
			buffer->Graphics->DrawImage(fondo, 0, 0, ancho, alto);


			juego->dibujar(buffer->Graphics, caballero, enemigo, fuego);
			buffer->Render(canvas);
			delete buffer;

			//HAMP Explica: sin buffer (parpadea). Comentar las lineas de arriba que usan buffer y quitar el comentario de las 2 siguientes
			//canvas->DrawImage(fondo, 0, 0, ancho, alto);
			//juego->dibujar(canvas, caballero, enemigo, fuego);

			lblEliminados->Text = Convert::ToString(juego->getEliminados());

			if (restantes < 0) {
				restantes = 0;

				// timer1->Enabled = false;

				MessageBox::Show(L"Ganaste", L"Ventanita",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
			}

			lblCantRestantes->Text = Convert::ToString(restantes);
				
		}

		System::Void pnlSprite_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
		{
			if (juego == nullptr) return;
			e->Graphics->DrawImage(fondo, 0, 0, pnlSprite->Width, pnlSprite->Height);
			juego->dibujar(e->Graphics, caballero, enemigo, fuego);
		}

		//HAMP Explica: al pulsar una tecla se guarda la direccion; la barra espaciadora lanza la bola
		System::Void FrmSprite_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
		{
			if (e->KeyCode == Keys::Down || e->KeyCode == Keys::S) teclaPresionada = Abajo;
			if (e->KeyCode == Keys::Left || e->KeyCode == Keys::A) teclaPresionada = Izquierda;
			if (e->KeyCode == Keys::Right || e->KeyCode == Keys::D) teclaPresionada = Derecha;
			if (e->KeyCode == Keys::Up || e->KeyCode == Keys::W) teclaPresionada = Arriba;

			if (e->KeyCode == Keys::Space && juego != nullptr) { 
				juego->lanzarBola(); 
				lblCantCansancio->Text = juego->getCaballeroCansancio().ToString();
			}

			if (e->KeyCode == Keys::C) {
				teclaPresionada = BotonC;
				juego->CaballeroDescanso(teclaPresionada);
				lblCantCansancio->Text = juego->getCaballeroCansancio().ToString();

			}
		}

		//HAMP Explica: al soltar la flecha el caballero se detiene (solo si era la flecha activa)
		System::Void FrmSprite_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
		{
			if (e->KeyCode == Keys::Down || e->KeyCode == Keys::S) { if (teclaPresionada == Abajo) teclaPresionada = Ninguno; }
			if (e->KeyCode == Keys::Left || e->KeyCode == Keys::A) { if (teclaPresionada == Izquierda) teclaPresionada = Ninguno; }
			if (e->KeyCode == Keys::Right || e->KeyCode == Keys::D) { if (teclaPresionada == Derecha) teclaPresionada = Ninguno; }
			if (e->KeyCode == Keys::Up || e->KeyCode == Keys::W) { if (teclaPresionada == Arriba) teclaPresionada = Ninguno; }
		}
	

};
}
