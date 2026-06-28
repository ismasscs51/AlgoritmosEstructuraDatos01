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
		}

		void mostrarLogin() {
			panelInicio->Visible = false;
			panelLogin->Visible = true;
			panelRegistro->Visible = false;
			panelMenuPrincipal->Visible = false;
		}

		void mostrarRegistro() {
			panelInicio->Visible = false;
			panelLogin->Visible = false;
			panelRegistro->Visible = true;
			panelMenuPrincipal->Visible = false;
		}

		void mostrarMenuPrincipal() {
			panelInicio->Visible = false;
			panelLogin->Visible = false;
			panelRegistro->Visible = false;
			panelMenuPrincipal->Visible = true;
		}

		void actualizarMenuPrincipal() {
			Usuario* usuario = sistema->getUsuarioActual();

			if (usuario != nullptr) {
				labelBienvenidaMenu->Text = "Bienvenido, " + gcnew System::String(usuario->getNombre().c_str());
				labelPuntosMenu->Text = "Puntos: " + usuario->getPuntos().ToString();
				
			}
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
			this->panelMenuPrincipal = (gcnew System::Windows::Forms::Panel());
			this->buttonCerrarsesion = (gcnew System::Windows::Forms::Button());
			this->buttonVerProgreso = (gcnew System::Windows::Forms::Button());
			this->buttonLeccion3 = (gcnew System::Windows::Forms::Button());
			this->buttonLeccion2 = (gcnew System::Windows::Forms::Button());
			this->buttonLeccion1 = (gcnew System::Windows::Forms::Button());
			this->labelCursoMenu = (gcnew System::Windows::Forms::Label());
			this->labelPuntosMenu = (gcnew System::Windows::Forms::Label());
			this->labelBienvenidaMenu = (gcnew System::Windows::Forms::Label());
			this->labelTituloMenu = (gcnew System::Windows::Forms::Label());
			this->buttoniniciarsesion = (gcnew System::Windows::Forms::Button());
			this->buttonCrearcuenta = (gcnew System::Windows::Forms::Button());
			this->Tituloinicial = (gcnew System::Windows::Forms::Label());
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
			this->panelInicio->SuspendLayout();
			this->panelMenuPrincipal->SuspendLayout();
			this->panelLogin->SuspendLayout();
			this->panelRegistro->SuspendLayout();
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
			// panelMenuPrincipal
			// 
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
			this->buttonVerProgreso->Location = System::Drawing::Point(23, 501);
			this->buttonVerProgreso->Name = L"buttonVerProgreso";
			this->buttonVerProgreso->Size = System::Drawing::Size(120, 23);
			this->buttonVerProgreso->TabIndex = 7;
			this->buttonVerProgreso->Text = L"Ver progreso";
			this->buttonVerProgreso->UseVisualStyleBackColor = true;
			this->buttonVerProgreso->Click += gcnew System::EventHandler(this, &MyForm::buttonVerProgreso_Click);
			// 
			// buttonLeccion3
			// 
			this->buttonLeccion3->Enabled = false;
			this->buttonLeccion3->Location = System::Drawing::Point(210, 356);
			this->buttonLeccion3->Name = L"buttonLeccion3";
			this->buttonLeccion3->Size = System::Drawing::Size(75, 38);
			this->buttonLeccion3->TabIndex = 6;
			this->buttonLeccion3->Text = L"Leccion 3";
			this->buttonLeccion3->UseVisualStyleBackColor = true;
			// 
			// buttonLeccion2
			// 
			this->buttonLeccion2->Enabled = false;
			this->buttonLeccion2->Location = System::Drawing::Point(210, 285);
			this->buttonLeccion2->Name = L"buttonLeccion2";
			this->buttonLeccion2->Size = System::Drawing::Size(75, 38);
			this->buttonLeccion2->TabIndex = 5;
			this->buttonLeccion2->Text = L"Leccion 2";
			this->buttonLeccion2->UseVisualStyleBackColor = true;
			// 
			// buttonLeccion1
			// 
			this->buttonLeccion1->Location = System::Drawing::Point(210, 215);
			this->buttonLeccion1->Name = L"buttonLeccion1";
			this->buttonLeccion1->Size = System::Drawing::Size(75, 38);
			this->buttonLeccion1->TabIndex = 4;
			this->buttonLeccion1->Text = L"Leccion 1";
			this->buttonLeccion1->UseVisualStyleBackColor = true;
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
			this->label5->Size = System::Drawing::Size(82, 16);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Contraseña: ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(114, 142);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(54, 16);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Correo: ";
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
			this->textBoxClaveLogin->Location = System::Drawing::Point(164, 196);
			this->textBoxClaveLogin->Name = L"textBoxClaveLogin";
			this->textBoxClaveLogin->Size = System::Drawing::Size(159, 22);
			this->textBoxClaveLogin->TabIndex = 1;
			this->textBoxClaveLogin->UseSystemPasswordChar = true;
			// 
			// textBoxCorreologin
			// 
			this->textBoxCorreologin->Location = System::Drawing::Point(164, 139);
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
			this->label3->Size = System::Drawing::Size(82, 16);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Contraseña: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(120, 170);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 16);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Correo: ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(114, 129);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 16);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Usuario: ";
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
			this->textBoxClaveRegistro->Location = System::Drawing::Point(171, 209);
			this->textBoxClaveRegistro->Name = L"textBoxClaveRegistro";
			this->textBoxClaveRegistro->Size = System::Drawing::Size(152, 22);
			this->textBoxClaveRegistro->TabIndex = 2;
			this->textBoxClaveRegistro->UseSystemPasswordChar = true;
			// 
			// textBoxCorreoRegistro
			// 
			this->textBoxCorreoRegistro->Location = System::Drawing::Point(171, 167);
			this->textBoxCorreoRegistro->Name = L"textBoxCorreoRegistro";
			this->textBoxCorreoRegistro->Size = System::Drawing::Size(152, 22);
			this->textBoxCorreoRegistro->TabIndex = 1;
			// 
			// textBoxNombreRegistro
			// 
			this->textBoxNombreRegistro->Location = System::Drawing::Point(171, 126);
			this->textBoxNombreRegistro->Name = L"textBoxNombreRegistro";
			this->textBoxNombreRegistro->Size = System::Drawing::Size(152, 22);
			this->textBoxNombreRegistro->TabIndex = 0;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(503, 564);
			this->Controls->Add(this->panelMenuPrincipal);
			this->Controls->Add(this->panelInicio);
			this->Controls->Add(this->panelLogin);
			this->Controls->Add(this->panelRegistro);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->panelInicio->ResumeLayout(false);
			this->panelMenuPrincipal->ResumeLayout(false);
			this->panelMenuPrincipal->PerformLayout();
			this->panelLogin->ResumeLayout(false);
			this->panelLogin->PerformLayout();
			this->panelRegistro->ResumeLayout(false);
			this->panelRegistro->PerformLayout();
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

		MessageBox::Show(gcnew String(datos.c_str()), "Bienvenido");
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

}
};
}
