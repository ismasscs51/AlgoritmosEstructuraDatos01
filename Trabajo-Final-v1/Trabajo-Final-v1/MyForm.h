#pragma once
#include "Duolingo.h"
#include <msclr\marshal_cppstd.h> //hace que el string del forms se transforme en un string de c++ algo haci entendi
                                 // ismael debe saber tambien agrego eso en el anterior trabajo

namespace TrabajoFinalv1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			sistema = new Duolingo();
			mostrarInicio();
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}

			delete sistema;
		}

	protected:

	private:
		/// <summary>

		void mostrarInicio() {
			panelInicio->Visible = true;
			panelLogin->Visible = false;
			panelRegistro->Visible = false;
			panelMenuPrincipal->Visible = false;
			panelPractica->Visible = false;
			panelRanking->Visible = false;
			panelDiccionario->Visible = false;
			panelRutaLeccion->Visible = false;
			panelProgreso->Visible = false;
			panelHistorial->Visible = false;
		}

		void mostrarLogin() {
			panelInicio->Visible = false;
			panelLogin->Visible = true;
			panelRegistro->Visible = false;
			panelMenuPrincipal->Visible = false;
			panelPractica->Visible = false;
			panelRanking->Visible = false;
			panelDiccionario->Visible = false;
			panelRutaLeccion->Visible = false;
			panelProgreso->Visible = false;
			panelHistorial->Visible = false;
		}

		void mostrarRegistro() {
			panelInicio->Visible = false;
			panelLogin->Visible = false;
			panelRegistro->Visible = true;
			panelMenuPrincipal->Visible = false;
			panelPractica->Visible = false;
			panelRanking->Visible = false;
			panelDiccionario->Visible = false;
			panelRutaLeccion->Visible = false;
			panelProgreso->Visible = false;
			panelHistorial->Visible = false;
		}

		void mostrarMenuPrincipal() {
			panelInicio->Visible = false;
			panelLogin->Visible = false;
			panelRegistro->Visible = false;
			panelMenuPrincipal->Visible = true;
			panelPractica->Visible = false;
			panelRanking->Visible = false;
			panelDiccionario->Visible = false;
			panelRutaLeccion->Visible = false;
			panelProgreso->Visible = false;
			panelHistorial->Visible = false;
		}

		void mostrarPractica() {
			panelInicio->Visible = false;
			panelLogin->Visible = false;
			panelRegistro->Visible = false;
			panelMenuPrincipal->Visible = false;
			panelPractica->Visible = true;
			panelRanking->Visible = false;
			panelDiccionario->Visible = false;
			panelRutaLeccion->Visible = false;
			panelProgreso->Visible = false;
			panelHistorial->Visible = false;
		}

		void mostrarRanking() {
			panelInicio->Visible = false;
			panelLogin->Visible = false;
			panelRegistro->Visible = false;
			panelMenuPrincipal->Visible = false;
			panelPractica->Visible = false;
			panelRanking->Visible = true;
			panelDiccionario->Visible = false;
			panelRutaLeccion->Visible = false;
			panelProgreso->Visible = false;
			panelHistorial->Visible = false;
		}

		void mostrarDiccionario() {
			panelInicio->Visible = false;
			panelLogin->Visible = false;
			panelRegistro->Visible = false;
			panelMenuPrincipal->Visible = false;
			panelPractica->Visible = false;
			panelRanking->Visible = false;
			panelDiccionario->Visible = true;
			panelRutaLeccion->Visible = false;
			panelProgreso->Visible = false;
			panelHistorial->Visible = false;
		}

		void mostrarRutaLeccion() {
			panelInicio->Visible = false;
			panelLogin->Visible = false;
			panelRegistro->Visible = false;
			panelMenuPrincipal->Visible = false;
			panelPractica->Visible = false;
			panelRanking->Visible = false;
			panelDiccionario->Visible = false;
			panelRutaLeccion->Visible = true;
			panelProgreso->Visible = false;
			panelHistorial->Visible = false;
		}

		void mostrarProgreso() {
			panelInicio->Visible = false;
			panelLogin->Visible = false;
			panelRegistro->Visible = false;
			panelMenuPrincipal->Visible = false;
			panelPractica->Visible = false;
			panelRanking->Visible = false;
			panelDiccionario->Visible = false;
			panelRutaLeccion->Visible = false;
			panelProgreso->Visible = true;
			panelHistorial->Visible = false;
		}

		void mostrarHistorial() {
			panelInicio->Visible = false;
			panelLogin->Visible = false;
			panelRegistro->Visible = false;
			panelMenuPrincipal->Visible = false;
			panelPractica->Visible = false;
			panelRanking->Visible = false;
			panelDiccionario->Visible = false;
			panelRutaLeccion->Visible = false;
			panelProgreso->Visible = false;
			panelHistorial->Visible = true;
		}

		void actualizarMenuPrincipal() {
			Usuario* usuario = sistema->getUsuarioActual();

			if (usuario != nullptr) {
				labelBienvenidaMenu->Text = "Bienvenido, " + gcnew System::String(usuario->getNombre().c_str());
				labelPuntosMenu->Text = "Puntos: " + usuario->getPuntos().ToString();
				
			}

			buttonLeccion1->Enabled = true;

			buttonLeccion2->Enabled = sistema->puedeIngresarLeccion(2);
			buttonLeccion3->Enabled = sistema->puedeIngresarLeccion(3);

			if (sistema->puedeIngresarLeccion(2)) {
				buttonLeccion2->Text = L"Leccion 2: Numeros";
			}
			else {
				buttonLeccion2->Text = L"Leccion 2: Numeros - Bloqueada";
			}

			if (sistema->puedeIngresarLeccion(3)) {
				buttonLeccion3->Text = L"Leccion 3: Animales";
			}
			else {
				buttonLeccion3->Text = L"Leccion 3: Animales - Bloqueada";
			}
		}

		void responderPregunta(char opcion) {
			bool correcta = sistema->responderEjercicioActual(opcion);

			if (correcta) {
				labelResultadoPractica->Text = L"Correcto +10 puntos";
			}
			else {
				labelResultadoPractica->Text = L"Incorrecto";
			}

			buttonOpcionA->Enabled = false;
			buttonOpcionB->Enabled = false;
			buttonOpcionC->Enabled = false;

			buttonSiguientePregunta->Visible = true;

			actualizarMenuPrincipal();
		}

		void mostrarPreguntaActual() {
			Ejercicio ejercicio = sistema->getEjercicioActual();

			labelNumeroPregunta->Text =
				"Pregunta " + sistema->getNumeroPregunta().ToString() +
				" de " + sistema->getTotalPreguntas().ToString();

			labelPregunta->Text = gcnew System::String(ejercicio.getPregunta().c_str());

			buttonOpcionA->Text = "A) " + gcnew System::String(ejercicio.getOpcionA().c_str());
			buttonOpcionB->Text = "B) " + gcnew System::String(ejercicio.getOpcionB().c_str());
			buttonOpcionC->Text = "C) " + gcnew System::String(ejercicio.getOpcionC().c_str());

			labelResultadoPractica->Text = "";

			buttonOpcionA->Enabled = true;
			buttonOpcionB->Enabled = true;
			buttonOpcionC->Enabled = true;

			buttonSiguientePregunta->Visible = false;
		}

		void actualizarPanelRanking() {
			string ranking = sistema->obtenerRankingUsuarios();

			richTextBoxRanking->Text = gcnew System::String(ranking.c_str());
		}

		void actualizarPanelDiccionario() {
			std::string diccionario = sistema->obtenerDiccionarioPalabras();

			richTextBoxDiccionario->Text = gcnew System::String(diccionario.c_str());
		}

		void actualizarPanelRutaLecciones() {
			string ruta = sistema->obtenerRutaLecciones();

			richTextBoxRutaLeccion->Text = gcnew System::String(ruta.c_str());
		}

		void actualizarPanelProgreso() {
			std::string progreso = sistema->obtenerProgresoActual();

			richTextBoxProgreso->Text = gcnew System::String(progreso.c_str());
		}

		void actualizarPanelHistorial() {
			std::string historial = sistema->obtenerHistorialRespuestas();

			richTextBoxHistorial->Text = gcnew System::String(historial.c_str());
		}

		Duolingo* sistema;
	private: System::Windows::Forms::Panel^ panelInicio;
	private: System::Windows::Forms::Label^ Tituloinicial;
	private: System::Windows::Forms::Panel^ panelLogin;
	private: System::Windows::Forms::Button^ buttoniniciarsesion;
	private: System::Windows::Forms::Button^ buttonCrearcuenta;
	private: System::Windows::Forms::Button^ buttonIngresarLogin;

	private: System::Windows::Forms::TextBox^ textBoxClaveLogin;
	private: System::Windows::Forms::TextBox^ textBoxCorreologin;
	private: System::Windows::Forms::Panel^ panelRegistro;
	private: System::Windows::Forms::Button^ buttonVolverlogin;
	private: System::Windows::Forms::Button^ buttonVolverRegistro;
	private: System::Windows::Forms::Button^ buttonRegistrarCuenta;
	private: System::Windows::Forms::TextBox^ textBoxClaveRegistro;
	private: System::Windows::Forms::TextBox^ textBoxCorreoRegistro;
	private: System::Windows::Forms::TextBox^ textBoxNombreRegistro;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panelMenuPrincipal;
	private: System::Windows::Forms::Label^ labelTituloMenu;
	private: System::Windows::Forms::Button^ buttonLeccion1;


	private: System::Windows::Forms::Label^ labelCursoMenu;
	private: System::Windows::Forms::Label^ labelPuntosMenu;
	private: System::Windows::Forms::Label^ labelBienvenidaMenu;
	private: System::Windows::Forms::Button^ buttonCerrarsesion;

	private: System::Windows::Forms::Button^ buttonVerProgreso;
	private: System::Windows::Forms::Button^ buttonLeccion3;
	private: System::Windows::Forms::Button^ buttonLeccion2;
private: System::Windows::Forms::Panel^ panelPractica;
private: System::Windows::Forms::Button^ buttonVolverMenu;


private: System::Windows::Forms::Label^ labelResultadoPractica;
private: System::Windows::Forms::Button^ buttonOpcionC;
private: System::Windows::Forms::Button^ buttonOpcionB;
private: System::Windows::Forms::Button^ buttonOpcionA;
private: System::Windows::Forms::Label^ labelPregunta;
private: System::Windows::Forms::Label^ labelNumeroPregunta;
private: System::Windows::Forms::Label^ labelTituloPractica;
private: System::Windows::Forms::Button^ buttonSiguientePregunta;
private: System::Windows::Forms::Button^ buttonVerHistorial;
private: System::Windows::Forms::Button^ buttonVerRanking;
private: System::Windows::Forms::Panel^ panelRanking;
private: System::Windows::Forms::Label^ labelTituloRanking;
private: System::Windows::Forms::Button^ buttonVolverRanking;
private: System::Windows::Forms::RichTextBox^ richTextBoxRanking;
private: System::Windows::Forms::Panel^ panelDiccionario;
private: System::Windows::Forms::RichTextBox^ richTextBoxDiccionario;

private: System::Windows::Forms::Label^ labelTituloDiccionario;
private: System::Windows::Forms::Button^ buttonVolverDiccionario;
private: System::Windows::Forms::Button^ buttonVerDiccionario;
private: System::Windows::Forms::Panel^ panelRutaLeccion;
private: System::Windows::Forms::Button^ buttonVolverRutaLeccion;


private: System::Windows::Forms::RichTextBox^ richTextBoxRutaLeccion;
private: System::Windows::Forms::Label^ labelTituloRutaLeccion;
private: System::Windows::Forms::Button^ buttonVerRutaLecciones;
private: System::Windows::Forms::Button^ buttonRankingQuicksort;
private: System::Windows::Forms::Button^ buttonRankingAVL;
private: System::Windows::Forms::Button^ buttonCargarDataset;
private: System::Windows::Forms::Panel^ panelProgreso;
private: System::Windows::Forms::Button^ buttonVolverProgreso;
private: System::Windows::Forms::RichTextBox^ richTextBoxProgreso;
private: System::Windows::Forms::Label^ labelProgreso;
private: System::Windows::Forms::Panel^ panelHistorial;
private: System::Windows::Forms::Button^ buttonVolverHistorial;

private: System::Windows::Forms::RichTextBox^ richTextBoxHistorial;
private: System::Windows::Forms::Label^ label6;





		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panelInicio = (gcnew System::Windows::Forms::Panel());
			this->buttoniniciarsesion = (gcnew System::Windows::Forms::Button());
			this->buttonCrearcuenta = (gcnew System::Windows::Forms::Button());
			this->Tituloinicial = (gcnew System::Windows::Forms::Label());
			this->panelPractica = (gcnew System::Windows::Forms::Panel());
			this->buttonSiguientePregunta = (gcnew System::Windows::Forms::Button());
			this->buttonVolverMenu = (gcnew System::Windows::Forms::Button());
			this->labelResultadoPractica = (gcnew System::Windows::Forms::Label());
			this->buttonOpcionC = (gcnew System::Windows::Forms::Button());
			this->buttonOpcionB = (gcnew System::Windows::Forms::Button());
			this->buttonOpcionA = (gcnew System::Windows::Forms::Button());
			this->labelPregunta = (gcnew System::Windows::Forms::Label());
			this->labelNumeroPregunta = (gcnew System::Windows::Forms::Label());
			this->labelTituloPractica = (gcnew System::Windows::Forms::Label());
			this->panelMenuPrincipal = (gcnew System::Windows::Forms::Panel());
			this->buttonCargarDataset = (gcnew System::Windows::Forms::Button());
			this->buttonVerRutaLecciones = (gcnew System::Windows::Forms::Button());
			this->buttonVerDiccionario = (gcnew System::Windows::Forms::Button());
			this->buttonVerRanking = (gcnew System::Windows::Forms::Button());
			this->buttonVerHistorial = (gcnew System::Windows::Forms::Button());
			this->buttonCerrarsesion = (gcnew System::Windows::Forms::Button());
			this->buttonVerProgreso = (gcnew System::Windows::Forms::Button());
			this->buttonLeccion3 = (gcnew System::Windows::Forms::Button());
			this->buttonLeccion2 = (gcnew System::Windows::Forms::Button());
			this->buttonLeccion1 = (gcnew System::Windows::Forms::Button());
			this->labelCursoMenu = (gcnew System::Windows::Forms::Label());
			this->labelPuntosMenu = (gcnew System::Windows::Forms::Label());
			this->labelBienvenidaMenu = (gcnew System::Windows::Forms::Label());
			this->labelTituloMenu = (gcnew System::Windows::Forms::Label());
			this->panelLogin = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->buttonVolverlogin = (gcnew System::Windows::Forms::Button());
			this->buttonIngresarLogin = (gcnew System::Windows::Forms::Button());
			this->textBoxClaveLogin = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCorreologin = (gcnew System::Windows::Forms::TextBox());
			this->panelRegistro = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonVolverRegistro = (gcnew System::Windows::Forms::Button());
			this->buttonRegistrarCuenta = (gcnew System::Windows::Forms::Button());
			this->textBoxClaveRegistro = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCorreoRegistro = (gcnew System::Windows::Forms::TextBox());
			this->textBoxNombreRegistro = (gcnew System::Windows::Forms::TextBox());
			this->panelRanking = (gcnew System::Windows::Forms::Panel());
			this->buttonRankingQuicksort = (gcnew System::Windows::Forms::Button());
			this->buttonRankingAVL = (gcnew System::Windows::Forms::Button());
			this->buttonVolverRanking = (gcnew System::Windows::Forms::Button());
			this->richTextBoxRanking = (gcnew System::Windows::Forms::RichTextBox());
			this->labelTituloRanking = (gcnew System::Windows::Forms::Label());
			this->panelDiccionario = (gcnew System::Windows::Forms::Panel());
			this->buttonVolverDiccionario = (gcnew System::Windows::Forms::Button());
			this->richTextBoxDiccionario = (gcnew System::Windows::Forms::RichTextBox());
			this->labelTituloDiccionario = (gcnew System::Windows::Forms::Label());
			this->panelRutaLeccion = (gcnew System::Windows::Forms::Panel());
			this->buttonVolverRutaLeccion = (gcnew System::Windows::Forms::Button());
			this->richTextBoxRutaLeccion = (gcnew System::Windows::Forms::RichTextBox());
			this->labelTituloRutaLeccion = (gcnew System::Windows::Forms::Label());
			this->panelProgreso = (gcnew System::Windows::Forms::Panel());
			this->buttonVolverProgreso = (gcnew System::Windows::Forms::Button());
			this->richTextBoxProgreso = (gcnew System::Windows::Forms::RichTextBox());
			this->labelProgreso = (gcnew System::Windows::Forms::Label());
			this->panelHistorial = (gcnew System::Windows::Forms::Panel());
			this->buttonVolverHistorial = (gcnew System::Windows::Forms::Button());
			this->richTextBoxHistorial = (gcnew System::Windows::Forms::RichTextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panelInicio->SuspendLayout();
			this->panelPractica->SuspendLayout();
			this->panelMenuPrincipal->SuspendLayout();
			this->panelLogin->SuspendLayout();
			this->panelRegistro->SuspendLayout();
			this->panelRanking->SuspendLayout();
			this->panelDiccionario->SuspendLayout();
			this->panelRutaLeccion->SuspendLayout();
			this->panelProgreso->SuspendLayout();
			this->panelHistorial->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelInicio
			// 
			this->panelInicio->Controls->Add(this->buttoniniciarsesion);
			this->panelInicio->Controls->Add(this->buttonCrearcuenta);
			this->panelInicio->Controls->Add(this->Tituloinicial);
			this->panelInicio->Location = System::Drawing::Point(12, 12);
			this->panelInicio->Name = L"panelInicio";
			this->panelInicio->Size = System::Drawing::Size(479, 540);
			this->panelInicio->TabIndex = 1;
			// 
			// buttoniniciarsesion
			// 
			this->buttoniniciarsesion->Location = System::Drawing::Point(129, 475);
			this->buttoniniciarsesion->Name = L"buttoniniciarsesion";
			this->buttoniniciarsesion->Size = System::Drawing::Size(220, 33);
			this->buttoniniciarsesion->TabIndex = 2;
			this->buttoniniciarsesion->Text = L"Iniciar sesion";
			this->buttoniniciarsesion->UseVisualStyleBackColor = true;
			this->buttoniniciarsesion->Click += gcnew System::EventHandler(this, &MyForm::buttoniniciarsesion_Click);
			// 
			// buttonCrearcuenta
			// 
			this->buttonCrearcuenta->Location = System::Drawing::Point(129, 425);
			this->buttonCrearcuenta->Name = L"buttonCrearcuenta";
			this->buttonCrearcuenta->Size = System::Drawing::Size(220, 33);
			this->buttonCrearcuenta->TabIndex = 1;
			this->buttonCrearcuenta->Text = L"Crear cuenta";
			this->buttonCrearcuenta->UseVisualStyleBackColor = true;
			this->buttonCrearcuenta->Click += gcnew System::EventHandler(this, &MyForm::buttonCrearcuenta_Click);
			// 
			// Tituloinicial
			// 
			this->Tituloinicial->BackColor = System::Drawing::SystemColors::Control;
			this->Tituloinicial->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Tituloinicial->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 19.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Tituloinicial->Location = System::Drawing::Point(96, 18);
			this->Tituloinicial->Name = L"Tituloinicial";
			this->Tituloinicial->Size = System::Drawing::Size(288, 94);
			this->Tituloinicial->TabIndex = 0;
			this->Tituloinicial->Text = L"Duolingo";
			this->Tituloinicial->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panelPractica
			// 
			this->panelPractica->Controls->Add(this->buttonSiguientePregunta);
			this->panelPractica->Controls->Add(this->buttonVolverMenu);
			this->panelPractica->Controls->Add(this->labelResultadoPractica);
			this->panelPractica->Controls->Add(this->buttonOpcionC);
			this->panelPractica->Controls->Add(this->buttonOpcionB);
			this->panelPractica->Controls->Add(this->buttonOpcionA);
			this->panelPractica->Controls->Add(this->labelPregunta);
			this->panelPractica->Controls->Add(this->labelNumeroPregunta);
			this->panelPractica->Controls->Add(this->labelTituloPractica);
			this->panelPractica->Location = System::Drawing::Point(12, 12);
			this->panelPractica->Name = L"panelPractica";
			this->panelPractica->Size = System::Drawing::Size(479, 540);
			this->panelPractica->TabIndex = 3;
			// 
			// buttonSiguientePregunta
			// 
			this->buttonSiguientePregunta->Location = System::Drawing::Point(80, 487);
			this->buttonSiguientePregunta->Name = L"buttonSiguientePregunta";
			this->buttonSiguientePregunta->Size = System::Drawing::Size(318, 37);
			this->buttonSiguientePregunta->TabIndex = 8;
			this->buttonSiguientePregunta->Text = L"Continuar";
			this->buttonSiguientePregunta->UseVisualStyleBackColor = true;
			this->buttonSiguientePregunta->Visible = false;
			this->buttonSiguientePregunta->Click += gcnew System::EventHandler(this, &MyForm::buttonSiguientePregunta_Click);
			// 
			// buttonVolverMenu
			// 
			this->buttonVolverMenu->Location = System::Drawing::Point(3, 13);
			this->buttonVolverMenu->Name = L"buttonVolverMenu";
			this->buttonVolverMenu->Size = System::Drawing::Size(117, 26);
			this->buttonVolverMenu->TabIndex = 7;
			this->buttonVolverMenu->Text = L"Volver al menu";
			this->buttonVolverMenu->UseVisualStyleBackColor = true;
			this->buttonVolverMenu->Click += gcnew System::EventHandler(this, &MyForm::buttonVolverMenu_Click);
			// 
			// labelResultadoPractica
			// 
			this->labelResultadoPractica->AutoSize = true;
			this->labelResultadoPractica->Location = System::Drawing::Point(161, 433);
			this->labelResultadoPractica->Name = L"labelResultadoPractica";
			this->labelResultadoPractica->Size = System::Drawing::Size(44, 16);
			this->labelResultadoPractica->TabIndex = 6;
			this->labelResultadoPractica->Text = L"label6";
			// 
			// buttonOpcionC
			// 
			this->buttonOpcionC->Location = System::Drawing::Point(185, 336);
			this->buttonOpcionC->Name = L"buttonOpcionC";
			this->buttonOpcionC->Size = System::Drawing::Size(100, 23);
			this->buttonOpcionC->TabIndex = 5;
			this->buttonOpcionC->Text = L"button3";
			this->buttonOpcionC->UseVisualStyleBackColor = true;
			this->buttonOpcionC->Click += gcnew System::EventHandler(this, &MyForm::buttonOpcionC_Click);
			// 
			// buttonOpcionB
			// 
			this->buttonOpcionB->Location = System::Drawing::Point(185, 285);
			this->buttonOpcionB->Name = L"buttonOpcionB";
			this->buttonOpcionB->Size = System::Drawing::Size(100, 23);
			this->buttonOpcionB->TabIndex = 4;
			this->buttonOpcionB->Text = L"button2";
			this->buttonOpcionB->UseVisualStyleBackColor = true;
			this->buttonOpcionB->Click += gcnew System::EventHandler(this, &MyForm::buttonOpcionB_Click);
			// 
			// buttonOpcionA
			// 
			this->buttonOpcionA->Location = System::Drawing::Point(185, 233);
			this->buttonOpcionA->Name = L"buttonOpcionA";
			this->buttonOpcionA->Size = System::Drawing::Size(100, 23);
			this->buttonOpcionA->TabIndex = 3;
			this->buttonOpcionA->Text = L"button1";
			this->buttonOpcionA->UseVisualStyleBackColor = true;
			this->buttonOpcionA->Click += gcnew System::EventHandler(this, &MyForm::buttonOpcionA_Click);
			// 
			// labelPregunta
			// 
			this->labelPregunta->AutoSize = true;
			this->labelPregunta->Location = System::Drawing::Point(114, 132);
			this->labelPregunta->Name = L"labelPregunta";
			this->labelPregunta->Size = System::Drawing::Size(44, 16);
			this->labelPregunta->TabIndex = 2;
			this->labelPregunta->Text = L"label6";
			// 
			// labelNumeroPregunta
			// 
			this->labelNumeroPregunta->AutoSize = true;
			this->labelNumeroPregunta->Location = System::Drawing::Point(357, 62);
			this->labelNumeroPregunta->Name = L"labelNumeroPregunta";
			this->labelNumeroPregunta->Size = System::Drawing::Size(100, 16);
			this->labelNumeroPregunta->TabIndex = 1;
			this->labelNumeroPregunta->Text = L"Pregunta 1 de 3";
			// 
			// labelTituloPractica
			// 
			this->labelTituloPractica->AutoSize = true;
			this->labelTituloPractica->Location = System::Drawing::Point(33, 62);
			this->labelTituloPractica->Name = L"labelTituloPractica";
			this->labelTituloPractica->Size = System::Drawing::Size(57, 16);
			this->labelTituloPractica->TabIndex = 0;
			this->labelTituloPractica->Text = L"Leccion:";
			// 
			// panelMenuPrincipal
			// 
			this->panelMenuPrincipal->Controls->Add(this->buttonCargarDataset);
			this->panelMenuPrincipal->Controls->Add(this->buttonVerRutaLecciones);
			this->panelMenuPrincipal->Controls->Add(this->buttonVerDiccionario);
			this->panelMenuPrincipal->Controls->Add(this->buttonVerRanking);
			this->panelMenuPrincipal->Controls->Add(this->buttonVerHistorial);
			this->panelMenuPrincipal->Controls->Add(this->buttonCerrarsesion);
			this->panelMenuPrincipal->Controls->Add(this->buttonVerProgreso);
			this->panelMenuPrincipal->Controls->Add(this->buttonLeccion3);
			this->panelMenuPrincipal->Controls->Add(this->buttonLeccion2);
			this->panelMenuPrincipal->Controls->Add(this->buttonLeccion1);
			this->panelMenuPrincipal->Controls->Add(this->labelCursoMenu);
			this->panelMenuPrincipal->Controls->Add(this->labelPuntosMenu);
			this->panelMenuPrincipal->Controls->Add(this->labelBienvenidaMenu);
			this->panelMenuPrincipal->Controls->Add(this->labelTituloMenu);
			this->panelMenuPrincipal->Location = System::Drawing::Point(12, 12);
			this->panelMenuPrincipal->Name = L"panelMenuPrincipal";
			this->panelMenuPrincipal->Size = System::Drawing::Size(479, 540);
			this->panelMenuPrincipal->TabIndex = 3;
			this->panelMenuPrincipal->Visible = false;
			// 
			// buttonCargarDataset
			// 
			this->buttonCargarDataset->Location = System::Drawing::Point(308, 475);
			this->buttonCargarDataset->Name = L"buttonCargarDataset";
			this->buttonCargarDataset->Size = System::Drawing::Size(116, 23);
			this->buttonCargarDataset->TabIndex = 13;
			this->buttonCargarDataset->Text = L"Carga dataset";
			this->buttonCargarDataset->UseVisualStyleBackColor = true;
			this->buttonCargarDataset->Click += gcnew System::EventHandler(this, &MyForm::buttonCargarDataset_Click);
			// 
			// buttonVerRutaLecciones
			// 
			this->buttonVerRutaLecciones->Location = System::Drawing::Point(308, 514);
			this->buttonVerRutaLecciones->Name = L"buttonVerRutaLecciones";
			this->buttonVerRutaLecciones->Size = System::Drawing::Size(116, 23);
			this->buttonVerRutaLecciones->TabIndex = 12;
			this->buttonVerRutaLecciones->Text = L"Ver ruta";
			this->buttonVerRutaLecciones->UseVisualStyleBackColor = true;
			this->buttonVerRutaLecciones->Click += gcnew System::EventHandler(this, &MyForm::buttonVerRutaLecciones_Click);
			// 
			// buttonVerDiccionario
			// 
			this->buttonVerDiccionario->Location = System::Drawing::Point(186, 514);
			this->buttonVerDiccionario->Name = L"buttonVerDiccionario";
			this->buttonVerDiccionario->Size = System::Drawing::Size(116, 23);
			this->buttonVerDiccionario->TabIndex = 11;
			this->buttonVerDiccionario->Text = L"Ver Diccionario";
			this->buttonVerDiccionario->UseVisualStyleBackColor = true;
			this->buttonVerDiccionario->Click += gcnew System::EventHandler(this, &MyForm::buttonVerDiccionario_Click);
			// 
			// buttonVerRanking
			// 
			this->buttonVerRanking->Location = System::Drawing::Point(183, 475);
			this->buttonVerRanking->Name = L"buttonVerRanking";
			this->buttonVerRanking->Size = System::Drawing::Size(119, 23);
			this->buttonVerRanking->TabIndex = 10;
			this->buttonVerRanking->Text = L"Ver ranking";
			this->buttonVerRanking->UseVisualStyleBackColor = true;
			this->buttonVerRanking->Click += gcnew System::EventHandler(this, &MyForm::buttonVerRanking_Click);
			// 
			// buttonVerHistorial
			// 
			this->buttonVerHistorial->Location = System::Drawing::Point(78, 514);
			this->buttonVerHistorial->Name = L"buttonVerHistorial";
			this->buttonVerHistorial->Size = System::Drawing::Size(102, 23);
			this->buttonVerHistorial->TabIndex = 9;
			this->buttonVerHistorial->Text = L"Ver Historial";
			this->buttonVerHistorial->UseVisualStyleBackColor = true;
			this->buttonVerHistorial->Click += gcnew System::EventHandler(this, &MyForm::buttonVerHistorial_Click);
			// 
			// buttonCerrarsesion
			// 
			this->buttonCerrarsesion->Location = System::Drawing::Point(360, 18);
			this->buttonCerrarsesion->Name = L"buttonCerrarsesion";
			this->buttonCerrarsesion->Size = System::Drawing::Size(116, 23);
			this->buttonCerrarsesion->TabIndex = 8;
			this->buttonCerrarsesion->Text = L"Cerrar sesion";
			this->buttonCerrarsesion->UseVisualStyleBackColor = true;
			this->buttonCerrarsesion->Click += gcnew System::EventHandler(this, &MyForm::buttonCerrarsesion_Click);
			// 
			// buttonVerProgreso
			// 
			this->buttonVerProgreso->Location = System::Drawing::Point(80, 475);
			this->buttonVerProgreso->Name = L"buttonVerProgreso";
			this->buttonVerProgreso->Size = System::Drawing::Size(100, 23);
			this->buttonVerProgreso->TabIndex = 7;
			this->buttonVerProgreso->Text = L"Ver progreso";
			this->buttonVerProgreso->UseVisualStyleBackColor = true;
			this->buttonVerProgreso->Click += gcnew System::EventHandler(this, &MyForm::buttonVerProgreso_Click);
			// 
			// buttonLeccion3
			// 
			this->buttonLeccion3->Enabled = false;
			this->buttonLeccion3->Location = System::Drawing::Point(201, 356);
			this->buttonLeccion3->Name = L"buttonLeccion3";
			this->buttonLeccion3->Size = System::Drawing::Size(92, 38);
			this->buttonLeccion3->TabIndex = 6;
			this->buttonLeccion3->Text = L"Leccion 3";
			this->buttonLeccion3->UseVisualStyleBackColor = true;
			this->buttonLeccion3->Click += gcnew System::EventHandler(this, &MyForm::buttonLeccion3_Click);
			// 
			// buttonLeccion2
			// 
			this->buttonLeccion2->Enabled = false;
			this->buttonLeccion2->Location = System::Drawing::Point(201, 285);
			this->buttonLeccion2->Name = L"buttonLeccion2";
			this->buttonLeccion2->Size = System::Drawing::Size(92, 38);
			this->buttonLeccion2->TabIndex = 5;
			this->buttonLeccion2->Text = L"Leccion 2";
			this->buttonLeccion2->UseVisualStyleBackColor = true;
			this->buttonLeccion2->Click += gcnew System::EventHandler(this, &MyForm::buttonLeccion2_Click);
			// 
			// buttonLeccion1
			// 
			this->buttonLeccion1->Location = System::Drawing::Point(202, 215);
			this->buttonLeccion1->Name = L"buttonLeccion1";
			this->buttonLeccion1->Size = System::Drawing::Size(92, 38);
			this->buttonLeccion1->TabIndex = 4;
			this->buttonLeccion1->Text = L"Leccion 1";
			this->buttonLeccion1->UseVisualStyleBackColor = true;
			this->buttonLeccion1->Click += gcnew System::EventHandler(this, &MyForm::buttonLeccion1_Click);
			// 
			// labelCursoMenu
			// 
			this->labelCursoMenu->AutoSize = true;
			this->labelCursoMenu->Location = System::Drawing::Point(14, 112);
			this->labelCursoMenu->Name = L"labelCursoMenu";
			this->labelCursoMenu->Size = System::Drawing::Size(129, 16);
			this->labelCursoMenu->TabIndex = 3;
			this->labelCursoMenu->Text = L"Curso: Ingles Basico";
			// 
			// labelPuntosMenu
			// 
			this->labelPuntosMenu->AutoSize = true;
			this->labelPuntosMenu->Location = System::Drawing::Point(14, 87);
			this->labelPuntosMenu->Name = L"labelPuntosMenu";
			this->labelPuntosMenu->Size = System::Drawing::Size(51, 16);
			this->labelPuntosMenu->TabIndex = 2;
			this->labelPuntosMenu->Text = L"Puntos:";
			// 
			// labelBienvenidaMenu
			// 
			this->labelBienvenidaMenu->AutoSize = true;
			this->labelBienvenidaMenu->Location = System::Drawing::Point(12, 62);
			this->labelBienvenidaMenu->Name = L"labelBienvenidaMenu";
			this->labelBienvenidaMenu->Size = System::Drawing::Size(78, 16);
			this->labelBienvenidaMenu->TabIndex = 1;
			this->labelBienvenidaMenu->Text = L"Bienvenido:";
			// 
			// labelTituloMenu
			// 
			this->labelTituloMenu->AutoSize = true;
			this->labelTituloMenu->Location = System::Drawing::Point(14, 18);
			this->labelTituloMenu->Name = L"labelTituloMenu";
			this->labelTituloMenu->Size = System::Drawing::Size(61, 16);
			this->labelTituloMenu->TabIndex = 0;
			this->labelTituloMenu->Text = L"Duolingo";
			// 
			// panelLogin
			// 
			this->panelLogin->Controls->Add(this->label5);
			this->panelLogin->Controls->Add(this->label4);
			this->panelLogin->Controls->Add(this->buttonVolverlogin);
			this->panelLogin->Controls->Add(this->buttonIngresarLogin);
			this->panelLogin->Controls->Add(this->textBoxClaveLogin);
			this->panelLogin->Controls->Add(this->textBoxCorreologin);
			this->panelLogin->Location = System::Drawing::Point(12, 12);
			this->panelLogin->Name = L"panelLogin";
			this->panelLogin->Size = System::Drawing::Size(479, 540);
			this->panelLogin->TabIndex = 3;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(86, 199);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(79, 16);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Contraseña:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(114, 142);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 16);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Correo:";
			// 
			// buttonVolverlogin
			// 
			this->buttonVolverlogin->Location = System::Drawing::Point(201, 307);
			this->buttonVolverlogin->Name = L"buttonVolverlogin";
			this->buttonVolverlogin->Size = System::Drawing::Size(84, 23);
			this->buttonVolverlogin->TabIndex = 3;
			this->buttonVolverlogin->Text = L"volver";
			this->buttonVolverlogin->UseVisualStyleBackColor = true;
			this->buttonVolverlogin->Click += gcnew System::EventHandler(this, &MyForm::buttonVolverlogin_Click);
			// 
			// buttonIngresarLogin
			// 
			this->buttonIngresarLogin->Location = System::Drawing::Point(201, 259);
			this->buttonIngresarLogin->Name = L"buttonIngresarLogin";
			this->buttonIngresarLogin->Size = System::Drawing::Size(84, 28);
			this->buttonIngresarLogin->TabIndex = 2;
			this->buttonIngresarLogin->Text = L"Ingresar";
			this->buttonIngresarLogin->UseVisualStyleBackColor = true;
			this->buttonIngresarLogin->Click += gcnew System::EventHandler(this, &MyForm::buttonIngresarLogin_Click);
			// 
			// textBoxClaveLogin
			// 
			this->textBoxClaveLogin->Location = System::Drawing::Point(170, 196);
			this->textBoxClaveLogin->Name = L"textBoxClaveLogin";
			this->textBoxClaveLogin->Size = System::Drawing::Size(159, 22);
			this->textBoxClaveLogin->TabIndex = 1;
			this->textBoxClaveLogin->UseSystemPasswordChar = true;
			// 
			// textBoxCorreologin
			// 
			this->textBoxCorreologin->Location = System::Drawing::Point(170, 139);
			this->textBoxCorreologin->Name = L"textBoxCorreologin";
			this->textBoxCorreologin->Size = System::Drawing::Size(159, 22);
			this->textBoxCorreologin->TabIndex = 0;
			// 
			// panelRegistro
			// 
			this->panelRegistro->Controls->Add(this->label3);
			this->panelRegistro->Controls->Add(this->label2);
			this->panelRegistro->Controls->Add(this->label1);
			this->panelRegistro->Controls->Add(this->buttonVolverRegistro);
			this->panelRegistro->Controls->Add(this->buttonRegistrarCuenta);
			this->panelRegistro->Controls->Add(this->textBoxClaveRegistro);
			this->panelRegistro->Controls->Add(this->textBoxCorreoRegistro);
			this->panelRegistro->Controls->Add(this->textBoxNombreRegistro);
			this->panelRegistro->Location = System::Drawing::Point(12, 12);
			this->panelRegistro->Name = L"panelRegistro";
			this->panelRegistro->Size = System::Drawing::Size(479, 540);
			this->panelRegistro->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(92, 212);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 16);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Contraseña:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(120, 170);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 16);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Correo:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(114, 129);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 16);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Usuario:";
			// 
			// buttonVolverRegistro
			// 
			this->buttonVolverRegistro->Location = System::Drawing::Point(210, 293);
			this->buttonVolverRegistro->Name = L"buttonVolverRegistro";
			this->buttonVolverRegistro->Size = System::Drawing::Size(75, 23);
			this->buttonVolverRegistro->TabIndex = 4;
			this->buttonVolverRegistro->Text = L"volver";
			this->buttonVolverRegistro->UseVisualStyleBackColor = true;
			this->buttonVolverRegistro->Click += gcnew System::EventHandler(this, &MyForm::buttonVolverRegistro_Click);
			// 
			// buttonRegistrarCuenta
			// 
			this->buttonRegistrarCuenta->Location = System::Drawing::Point(199, 264);
			this->buttonRegistrarCuenta->Name = L"buttonRegistrarCuenta";
			this->buttonRegistrarCuenta->Size = System::Drawing::Size(95, 23);
			this->buttonRegistrarCuenta->TabIndex = 3;
			this->buttonRegistrarCuenta->Text = L"Registrarse";
			this->buttonRegistrarCuenta->UseVisualStyleBackColor = true;
			this->buttonRegistrarCuenta->Click += gcnew System::EventHandler(this, &MyForm::buttonRegistrarCuenta_Click);
			// 
			// textBoxClaveRegistro
			// 
			this->textBoxClaveRegistro->Location = System::Drawing::Point(177, 209);
			this->textBoxClaveRegistro->Name = L"textBoxClaveRegistro";
			this->textBoxClaveRegistro->Size = System::Drawing::Size(152, 22);
			this->textBoxClaveRegistro->TabIndex = 2;
			this->textBoxClaveRegistro->UseSystemPasswordChar = true;
			// 
			// textBoxCorreoRegistro
			// 
			this->textBoxCorreoRegistro->Location = System::Drawing::Point(177, 167);
			this->textBoxCorreoRegistro->Name = L"textBoxCorreoRegistro";
			this->textBoxCorreoRegistro->Size = System::Drawing::Size(152, 22);
			this->textBoxCorreoRegistro->TabIndex = 1;
			// 
			// textBoxNombreRegistro
			// 
			this->textBoxNombreRegistro->Location = System::Drawing::Point(177, 126);
			this->textBoxNombreRegistro->Name = L"textBoxNombreRegistro";
			this->textBoxNombreRegistro->Size = System::Drawing::Size(152, 22);
			this->textBoxNombreRegistro->TabIndex = 0;
			// 
			// panelRanking
			// 
			this->panelRanking->Controls->Add(this->buttonRankingQuicksort);
			this->panelRanking->Controls->Add(this->buttonRankingAVL);
			this->panelRanking->Controls->Add(this->buttonVolverRanking);
			this->panelRanking->Controls->Add(this->richTextBoxRanking);
			this->panelRanking->Controls->Add(this->labelTituloRanking);
			this->panelRanking->Location = System::Drawing::Point(12, 12);
			this->panelRanking->Name = L"panelRanking";
			this->panelRanking->Size = System::Drawing::Size(479, 540);
			this->panelRanking->TabIndex = 5;
			// 
			// buttonRankingQuicksort
			// 
			this->buttonRankingQuicksort->Location = System::Drawing::Point(274, 454);
			this->buttonRankingQuicksort->Name = L"buttonRankingQuicksort";
			this->buttonRankingQuicksort->Size = System::Drawing::Size(141, 27);
			this->buttonRankingQuicksort->TabIndex = 4;
			this->buttonRankingQuicksort->Text = L"Ranking Quicksort";
			this->buttonRankingQuicksort->UseVisualStyleBackColor = true;
			this->buttonRankingQuicksort->Click += gcnew System::EventHandler(this, &MyForm::buttonRankingQuicksort_Click);
			// 
			// buttonRankingAVL
			// 
			this->buttonRankingAVL->Location = System::Drawing::Point(62, 454);
			this->buttonRankingAVL->Name = L"buttonRankingAVL";
			this->buttonRankingAVL->Size = System::Drawing::Size(147, 27);
			this->buttonRankingAVL->TabIndex = 3;
			this->buttonRankingAVL->Text = L"Ranking Arbol";
			this->buttonRankingAVL->UseVisualStyleBackColor = true;
			this->buttonRankingAVL->Click += gcnew System::EventHandler(this, &MyForm::buttonRankingAVL_Click);
			// 
			// buttonVolverRanking
			// 
			this->buttonVolverRanking->Location = System::Drawing::Point(144, 487);
			this->buttonVolverRanking->Name = L"buttonVolverRanking";
			this->buttonVolverRanking->Size = System::Drawing::Size(191, 37);
			this->buttonVolverRanking->TabIndex = 2;
			this->buttonVolverRanking->Text = L"Volver al Menu";
			this->buttonVolverRanking->UseVisualStyleBackColor = true;
			this->buttonVolverRanking->Click += gcnew System::EventHandler(this, &MyForm::buttonVolverRanking_Click);
			// 
			// richTextBoxRanking
			// 
			this->richTextBoxRanking->Location = System::Drawing::Point(62, 87);
			this->richTextBoxRanking->Name = L"richTextBoxRanking";
			this->richTextBoxRanking->ReadOnly = true;
			this->richTextBoxRanking->Size = System::Drawing::Size(351, 349);
			this->richTextBoxRanking->TabIndex = 1;
			this->richTextBoxRanking->Text = L"";
			// 
			// labelTituloRanking
			// 
			this->labelTituloRanking->AutoSize = true;
			this->labelTituloRanking->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTituloRanking->Location = System::Drawing::Point(112, 32);
			this->labelTituloRanking->Name = L"labelTituloRanking";
			this->labelTituloRanking->Size = System::Drawing::Size(251, 30);
			this->labelTituloRanking->TabIndex = 0;
			this->labelTituloRanking->Text = L"Ranking de Usuarios";
			// 
			// panelDiccionario
			// 
			this->panelDiccionario->Controls->Add(this->buttonVolverDiccionario);
			this->panelDiccionario->Controls->Add(this->richTextBoxDiccionario);
			this->panelDiccionario->Controls->Add(this->labelTituloDiccionario);
			this->panelDiccionario->Location = System::Drawing::Point(12, 12);
			this->panelDiccionario->Name = L"panelDiccionario";
			this->panelDiccionario->Size = System::Drawing::Size(479, 540);
			this->panelDiccionario->TabIndex = 6;
			// 
			// buttonVolverDiccionario
			// 
			this->buttonVolverDiccionario->Location = System::Drawing::Point(144, 487);
			this->buttonVolverDiccionario->Name = L"buttonVolverDiccionario";
			this->buttonVolverDiccionario->Size = System::Drawing::Size(219, 37);
			this->buttonVolverDiccionario->TabIndex = 2;
			this->buttonVolverDiccionario->Text = L"Volver al menu";
			this->buttonVolverDiccionario->UseVisualStyleBackColor = true;
			this->buttonVolverDiccionario->Click += gcnew System::EventHandler(this, &MyForm::buttonVolverDiccionario_Click);
			// 
			// richTextBoxDiccionario
			// 
			this->richTextBoxDiccionario->Location = System::Drawing::Point(62, 81);
			this->richTextBoxDiccionario->Name = L"richTextBoxDiccionario";
			this->richTextBoxDiccionario->ReadOnly = true;
			this->richTextBoxDiccionario->Size = System::Drawing::Size(353, 368);
			this->richTextBoxDiccionario->TabIndex = 1;
			this->richTextBoxDiccionario->Text = L"";
			// 
			// labelTituloDiccionario
			// 
			this->labelTituloDiccionario->AutoSize = true;
			this->labelTituloDiccionario->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTituloDiccionario->Location = System::Drawing::Point(149, 28);
			this->labelTituloDiccionario->Name = L"labelTituloDiccionario";
			this->labelTituloDiccionario->Size = System::Drawing::Size(174, 34);
			this->labelTituloDiccionario->TabIndex = 0;
			this->labelTituloDiccionario->Text = L"Diccionario";
			// 
			// panelRutaLeccion
			// 
			this->panelRutaLeccion->Controls->Add(this->buttonVolverRutaLeccion);
			this->panelRutaLeccion->Controls->Add(this->richTextBoxRutaLeccion);
			this->panelRutaLeccion->Controls->Add(this->labelTituloRutaLeccion);
			this->panelRutaLeccion->Location = System::Drawing::Point(12, 12);
			this->panelRutaLeccion->Name = L"panelRutaLeccion";
			this->panelRutaLeccion->Size = System::Drawing::Size(479, 540);
			this->panelRutaLeccion->TabIndex = 7;
			this->panelRutaLeccion->Visible = false;
			// 
			// buttonVolverRutaLeccion
			// 
			this->buttonVolverRutaLeccion->Location = System::Drawing::Point(139, 487);
			this->buttonVolverRutaLeccion->Name = L"buttonVolverRutaLeccion";
			this->buttonVolverRutaLeccion->Size = System::Drawing::Size(224, 31);
			this->buttonVolverRutaLeccion->TabIndex = 2;
			this->buttonVolverRutaLeccion->Text = L"Volver al menu";
			this->buttonVolverRutaLeccion->UseVisualStyleBackColor = true;
			this->buttonVolverRutaLeccion->Click += gcnew System::EventHandler(this, &MyForm::buttonVolverRutaLeccion_Click);
			// 
			// richTextBoxRutaLeccion
			// 
			this->richTextBoxRutaLeccion->Location = System::Drawing::Point(71, 81);
			this->richTextBoxRutaLeccion->Name = L"richTextBoxRutaLeccion";
			this->richTextBoxRutaLeccion->ReadOnly = true;
			this->richTextBoxRutaLeccion->Size = System::Drawing::Size(353, 355);
			this->richTextBoxRutaLeccion->TabIndex = 1;
			this->richTextBoxRutaLeccion->Text = L"";
			// 
			// labelTituloRutaLeccion
			// 
			this->labelTituloRutaLeccion->AutoSize = true;
			this->labelTituloRutaLeccion->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTituloRutaLeccion->Location = System::Drawing::Point(111, 28);
			this->labelTituloRutaLeccion->Name = L"labelTituloRutaLeccion";
			this->labelTituloRutaLeccion->Size = System::Drawing::Size(264, 31);
			this->labelTituloRutaLeccion->TabIndex = 0;
			this->labelTituloRutaLeccion->Text = L"Ruta de Aprendizaje";
			// 
			// panelProgreso
			// 
			this->panelProgreso->Controls->Add(this->buttonVolverProgreso);
			this->panelProgreso->Controls->Add(this->richTextBoxProgreso);
			this->panelProgreso->Controls->Add(this->labelProgreso);
			this->panelProgreso->Location = System::Drawing::Point(12, 12);
			this->panelProgreso->Name = L"panelProgreso";
			this->panelProgreso->Size = System::Drawing::Size(479, 540);
			this->panelProgreso->TabIndex = 8;
			// 
			// buttonVolverProgreso
			// 
			this->buttonVolverProgreso->Location = System::Drawing::Point(143, 484);
			this->buttonVolverProgreso->Name = L"buttonVolverProgreso";
			this->buttonVolverProgreso->Size = System::Drawing::Size(206, 36);
			this->buttonVolverProgreso->TabIndex = 2;
			this->buttonVolverProgreso->Text = L"Volver al menu";
			this->buttonVolverProgreso->UseVisualStyleBackColor = true;
			this->buttonVolverProgreso->Click += gcnew System::EventHandler(this, &MyForm::buttonVolverProgreso_Click);
			// 
			// richTextBoxProgreso
			// 
			this->richTextBoxProgreso->Location = System::Drawing::Point(71, 100);
			this->richTextBoxProgreso->Name = L"richTextBoxProgreso";
			this->richTextBoxProgreso->ReadOnly = true;
			this->richTextBoxProgreso->Size = System::Drawing::Size(342, 348);
			this->richTextBoxProgreso->TabIndex = 1;
			this->richTextBoxProgreso->Text = L"";
			// 
			// labelProgreso
			// 
			this->labelProgreso->AutoSize = true;
			this->labelProgreso->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelProgreso->Location = System::Drawing::Point(117, 42);
			this->labelProgreso->Name = L"labelProgreso";
			this->labelProgreso->Size = System::Drawing::Size(255, 31);
			this->labelProgreso->TabIndex = 0;
			this->labelProgreso->Text = L"Progreso de Usuario";
			// 
			// panelHistorial
			// 
			this->panelHistorial->Controls->Add(this->buttonVolverHistorial);
			this->panelHistorial->Controls->Add(this->richTextBoxHistorial);
			this->panelHistorial->Controls->Add(this->label6);
			this->panelHistorial->Location = System::Drawing::Point(12, 12);
			this->panelHistorial->Name = L"panelHistorial";
			this->panelHistorial->Size = System::Drawing::Size(479, 540);
			this->panelHistorial->TabIndex = 9;
			this->panelHistorial->Visible = false;
			// 
			// buttonVolverHistorial
			// 
			this->buttonVolverHistorial->Location = System::Drawing::Point(150, 475);
			this->buttonVolverHistorial->Name = L"buttonVolverHistorial";
			this->buttonVolverHistorial->Size = System::Drawing::Size(185, 35);
			this->buttonVolverHistorial->TabIndex = 2;
			this->buttonVolverHistorial->Text = L"Volver al menu";
			this->buttonVolverHistorial->UseVisualStyleBackColor = true;
			this->buttonVolverHistorial->Click += gcnew System::EventHandler(this, &MyForm::buttonVolverHistorial_Click);
			// 
			// richTextBoxHistorial
			// 
			this->richTextBoxHistorial->Location = System::Drawing::Point(71, 100);
			this->richTextBoxHistorial->Name = L"richTextBoxHistorial";
			this->richTextBoxHistorial->ReadOnly = true;
			this->richTextBoxHistorial->Size = System::Drawing::Size(342, 336);
			this->richTextBoxHistorial->TabIndex = 1;
			this->richTextBoxHistorial->Text = L"";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(110, 44);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(262, 31);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Historial de Usuario";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(503, 564);
			this->Controls->Add(this->panelLogin);
			this->Controls->Add(this->panelRegistro);
			this->Controls->Add(this->panelInicio);
			this->Controls->Add(this->panelHistorial);
			this->Controls->Add(this->panelProgreso);
			this->Controls->Add(this->panelMenuPrincipal);
			this->Controls->Add(this->panelRanking);
			this->Controls->Add(this->panelRutaLeccion);
			this->Controls->Add(this->panelDiccionario);
			this->Controls->Add(this->panelPractica);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->panelInicio->ResumeLayout(false);
			this->panelPractica->ResumeLayout(false);
			this->panelPractica->PerformLayout();
			this->panelMenuPrincipal->ResumeLayout(false);
			this->panelMenuPrincipal->PerformLayout();
			this->panelLogin->ResumeLayout(false);
			this->panelLogin->PerformLayout();
			this->panelRegistro->ResumeLayout(false);
			this->panelRegistro->PerformLayout();
			this->panelRanking->ResumeLayout(false);
			this->panelRanking->PerformLayout();
			this->panelDiccionario->ResumeLayout(false);
			this->panelDiccionario->PerformLayout();
			this->panelRutaLeccion->ResumeLayout(false);
			this->panelRutaLeccion->PerformLayout();
			this->panelProgreso->ResumeLayout(false);
			this->panelProgreso->PerformLayout();
			this->panelHistorial->ResumeLayout(false);
			this->panelHistorial->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void buttonCrearcuenta_Click(System::Object^ sender, System::EventArgs^ e) {
		mostrarRegistro();
	}
private: System::Void buttoniniciarsesion_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarLogin();

}
private: System::Void buttonVolverRegistro_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarInicio();
}
private: System::Void buttonVolverlogin_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarInicio();
}
private: System::Void buttonIngresarLogin_Click(System::Object^ sender, System::EventArgs^ e) {

	string correo = msclr::interop::marshal_as<string>(textBoxCorreologin->Text);
	string clave = msclr::interop::marshal_as<string>(textBoxClaveLogin->Text);

	bool logincorrecto = sistema->iniciarSesion(correo, clave);

	if (logincorrecto) {
		Usuario* usuario = sistema->getUsuarioActual();
		string datos = usuario->mostrarDatos();
		actualizarMenuPrincipal();
		mostrarMenuPrincipal();	

		
	}
	else {
		MessageBox::Show("Correo o contraseña incorrectos.");
	}
}
private: System::Void buttonRegistrarCuenta_Click(System::Object^ sender, System::EventArgs^ e) {

	string nombre = msclr::interop::marshal_as<string>(textBoxNombreRegistro->Text);
	string correo = msclr::interop::marshal_as<string>(textBoxCorreoRegistro->Text);
	string clave = msclr::interop::marshal_as<string>(textBoxClaveRegistro->Text);

	if (nombre == "" || correo == "" || clave == "") {
		MessageBox::Show("Debe completar todos los campos.");
		return;

	}

	bool registrado = sistema->registrarUsuario(nombre, correo, clave);

	if (registrado) {
		MessageBox::Show("Cuenta creada correctamente");

		textBoxNombreRegistro->Clear();
		textBoxCorreoRegistro->Clear();
		textBoxClaveRegistro->Clear();

		mostrarLogin();
	}
	else {
		MessageBox::Show("No se pudo registrar, El correo ya existe");
	}

}
private: System::Void buttonCerrarsesion_Click(System::Object^ sender, System::EventArgs^ e) {
	sistema->cerrarSesion();
	mostrarInicio();
}
private: System::Void buttonVerProgreso_Click(System::Object^ sender, System::EventArgs^ e) {
	actualizarPanelProgreso();
	mostrarProgreso();
}
private: System::Void buttonLeccion1_Click(System::Object^ sender, System::EventArgs^ e) {
	sistema->iniciarLeccionSaludos();

	mostrarPreguntaActual();
	mostrarPractica();
}
private: System::Void buttonVolverMenu_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarMenuPrincipal();

}
private: System::Void buttonOpcionA_Click(System::Object^ sender, System::EventArgs^ e) {
	responderPregunta('A');


}
private: System::Void buttonOpcionB_Click(System::Object^ sender, System::EventArgs^ e) {
	responderPregunta('B');

}
private: System::Void buttonOpcionC_Click(System::Object^ sender, System::EventArgs^ e) {
	responderPregunta('C');

}
private: System::Void buttonSiguientePregunta_Click(System::Object^ sender, System::EventArgs^ e) {
	if (sistema->quedanPreguntas()) {
		sistema->cargarSiguientePregunta();
		mostrarPreguntaActual();
	}
	else {
		std::string resumen = sistema->obtenerResumenLeccion();

		MessageBox::Show(
			gcnew System::String(resumen.c_str()),
			"Resultado"
		);

		actualizarMenuPrincipal();
		mostrarMenuPrincipal();
	}

}
private: System::Void buttonVerHistorial_Click(System::Object^ sender, System::EventArgs^ e) {
	actualizarPanelHistorial();
	mostrarHistorial();

}
private: System::Void buttonVerRanking_Click(System::Object^ sender, System::EventArgs^ e) {
	    string ranking = sistema->obtenerRankingUsuarios();
	    richTextBoxRanking->Text = gcnew System::String(ranking.c_str());

	mostrarRanking();

}
private: System::Void buttonVolverRanking_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarMenuPrincipal();

}
private: System::Void buttonVerDiccionario_Click(System::Object^ sender, System::EventArgs^ e) {
	actualizarPanelDiccionario();
	mostrarDiccionario();

}
private: System::Void buttonVolverDiccionario_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarMenuPrincipal();

}
private: System::Void buttonVolverRutaLeccion_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarMenuPrincipal();

}
private: System::Void buttonVerRutaLecciones_Click(System::Object^ sender, System::EventArgs^ e) {
	actualizarPanelRutaLecciones();
	mostrarRutaLeccion();
}
private: System::Void buttonRankingAVL_Click(System::Object^ sender, System::EventArgs^ e) {
	labelTituloRanking->Text = L"Ranking AVL";

	    string ranking = sistema->obtenerRankingUsuarios();
	    richTextBoxRanking->Text = gcnew System::String(ranking.c_str());

}
private: System::Void buttonRankingQuicksort_Click(System::Object^ sender, System::EventArgs^ e) {
	labelTituloRanking->Text = L"Ranking QuickSort";

	    string ranking = sistema->obtenerRankingQuickSort();
	    richTextBoxRanking->Text = gcnew System::String(ranking.c_str());

}
private: System::Void buttonCargarDataset_Click(System::Object^ sender, System::EventArgs^ e) {
	string resultado = sistema->cargarDatasetPrueba();

	MessageBox::Show(
		gcnew System::String(resultado.c_str()),
		"Dataset"
	);

	actualizarMenuPrincipal();

}
private: System::Void buttonLeccion2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!sistema->puedeIngresarLeccion(2)) {
		MessageBox::Show("Necesitas al menos 30 puntos para desbloquear esta leccion.");
		return;
	}

	labelTituloPractica->Text = L"Leccion 2: Numeros";

	sistema->iniciarLeccionNumeros();

	mostrarPreguntaActual();
	mostrarPractica();

}
private: System::Void buttonLeccion3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!sistema->puedeIngresarLeccion(3)) {
		MessageBox::Show("Necesitas al menos 60 puntos para desbloquear esta leccion.");
		return;
	}

	labelTituloPractica->Text = L"Leccion 3: Animales";

	sistema->iniciarLeccionAnimales();

	mostrarPreguntaActual();
	mostrarPractica();

}
private: System::Void buttonVolverProgreso_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarMenuPrincipal();

}
private: System::Void buttonVolverHistorial_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarMenuPrincipal();

}
};
}
