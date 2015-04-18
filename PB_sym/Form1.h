#pragma once

	extern char aK1, aK2, aK3, aK4;
	extern char L1,  L2,  L3,  L4;
	extern char line1[80], line2[80];

	void int_znak();      // wywo³ywana przerwaniowo gdy odebrano znak z konsoli
	void int_sym_znak();  // wywo³ywana przerwaniowo gdy odebrano znak z obiektu
	void inicjuj(void);         // wywo³ywana JEDNORAZOWO na pocz¹tku
	void oblicz(void);          // wywo³ywana co cykl (co 0.1 sek )

	void klaw_F1(void);      // funkcja wywo³ywana po naciœniêciu F1 na konsoli
	void klaw_F2(void);      // funkcja wywo³ywana po naciœniêciu F2 na konsoli
	void klaw_F3(void);      // funkcja wywo³ywana po naciœniêciu F3 na konsoli
	void klaw_F4(void);      // funkcja wywo³ywana po naciœniêciu F4 na konsoli

	// ----------------------------------------------------------------------

	char fl_ini=1, cc_znak=0, cx_znak=0;
	char buf_nad[260], fl_nad=0; int buf_ind1=0, buf_ind2=0;

	char tr_sym=0, rc_sym=0;
	char buf_sym[260], fl_sym=0; int sym_ind1=0, sym_ind2=0;

	char sym_recv_char(void)
	{
		char cc=tr_sym; tr_sym=0; return cc;
	}

	void sym_send_char(char cc)
	{
		fl_sym=1; ++sym_ind2; sym_ind2&=0x00FF; buf_sym[sym_ind2]=cc; fl_sym=0;
	}

	void sym_send_string(char * s)
	{
		while(*s) sym_send_char(*(s++)); 
	}

	void sym_trans_char(char cc)
	{
		tr_sym=cc;  int_sym_znak();
	}

	void sym_trans_string(char * s)
	{
		while(*s) sym_trans_char(*(s++)); 
	}

    char recv_char(void)
	{
		char cc=cc_znak; cc_znak=0; return cc;
	}

	void send_char(char cc)
	{
		fl_nad=1; ++buf_ind2; buf_ind2&=0x00FF; buf_nad[buf_ind2]=cc; fl_nad=0;
	}

	void send_string(char * s)
	{
		while(*s) send_char(*(s++)); 
	}

	void trans_char(char cc)
	{
		cc_znak=cc;  int_znak();
	}

	void trans_string(char * s)
	{
		while(*s) trans_char(*(s++)); 
	}


namespace PB_sym {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

//#include "UserFunc.h"

	void trans_char(char c);       // wyœlij jeden znak z konsoli do PB  
	void trans_string(char * s);   // wyœlij tekst (string) z konsoli do PB  

	//void ustaw_wy();

	char stan_z=1;

	char sym_X1, sym_X2, sym_X3, sym_TM;           // stany czujnikow obiektu
	char sym_Z1, sym_Z2, sym_Z3, sym_GR;           // stany zaworow obiektu

	int  wlvl, temp;               // poziom i temperatura wody w zbiorniku

	// -----------------------------------------------------------------------


	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button31;
	private: System::Windows::Forms::Button^  button30;
	private: System::Windows::Forms::Button^  button29;
	private: System::Windows::Forms::Button^  button28;
	private: System::Windows::Forms::Button^  button27;
	private: System::Windows::Forms::Button^  button26;
	private: System::Windows::Forms::Button^  button25;
	private: System::Windows::Forms::Button^  button24;
	private: System::Windows::Forms::Button^  button23;
	private: System::Windows::Forms::Button^  button22;
	private: System::Windows::Forms::Button^  button21;
	private: System::Windows::Forms::Button^  button20;
	private: System::Windows::Forms::Button^  button19;
	private: System::Windows::Forms::Button^  button18;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button34;
	private: System::Windows::Forms::Button^  button33;
	private: System::Windows::Forms::Button^  button32;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::GroupBox^  groupBox3;


	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::TextBox^  textBox15;

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button34 = (gcnew System::Windows::Forms::Button());
			this->button33 = (gcnew System::Windows::Forms::Button());
			this->button32 = (gcnew System::Windows::Forms::Button());
			this->button31 = (gcnew System::Windows::Forms::Button());
			this->button30 = (gcnew System::Windows::Forms::Button());
			this->button29 = (gcnew System::Windows::Forms::Button());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button8);
			this->groupBox1->Controls->Add(this->button7);
			this->groupBox1->Controls->Add(this->button6);
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Location = System::Drawing::Point(26, 41);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(367, 211);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Sterownik PB";
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button8->Location = System::Drawing::Point(257, 145);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(63, 41);
			this->button8->TabIndex = 9;
			this->button8->Text = L"K4";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button7->Location = System::Drawing::Point(185, 145);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(66, 41);
			this->button7->TabIndex = 8;
			this->button7->Text = L"K3";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button6->Location = System::Drawing::Point(112, 145);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(66, 41);
			this->button6->TabIndex = 7;
			this->button6->Text = L"K2";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button5->Location = System::Drawing::Point(40, 145);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(66, 41);
			this->button5->TabIndex = 6;
			this->button5->Text = L"K1";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(268, 107);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(40, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"L4";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(200, 107);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(40, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"L3";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(128, 107);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(40, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"L2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Control;
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(55, 107);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(40, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"L1";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Courier New", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->textBox2->ForeColor = System::Drawing::SystemColors::Window;
			this->textBox2->Location = System::Drawing::Point(40, 61);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(280, 31);
			this->textBox2->TabIndex = 1;
			this->textBox2->Text = L"12345678901234567890";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->textBox1->ForeColor = System::Drawing::SystemColors::Window;
			this->textBox1->Location = System::Drawing::Point(40, 24);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(280, 31);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"abcdefghijklmnopqrst";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button34);
			this->groupBox2->Controls->Add(this->button33);
			this->groupBox2->Controls->Add(this->button32);
			this->groupBox2->Controls->Add(this->button31);
			this->groupBox2->Controls->Add(this->button30);
			this->groupBox2->Controls->Add(this->button29);
			this->groupBox2->Controls->Add(this->button28);
			this->groupBox2->Controls->Add(this->button27);
			this->groupBox2->Controls->Add(this->button26);
			this->groupBox2->Controls->Add(this->button25);
			this->groupBox2->Controls->Add(this->button24);
			this->groupBox2->Controls->Add(this->button23);
			this->groupBox2->Controls->Add(this->button22);
			this->groupBox2->Controls->Add(this->button21);
			this->groupBox2->Controls->Add(this->button20);
			this->groupBox2->Controls->Add(this->button19);
			this->groupBox2->Controls->Add(this->button18);
			this->groupBox2->Controls->Add(this->button17);
			this->groupBox2->Controls->Add(this->button16);
			this->groupBox2->Controls->Add(this->button15);
			this->groupBox2->Controls->Add(this->button14);
			this->groupBox2->Controls->Add(this->button13);
			this->groupBox2->Controls->Add(this->button12);
			this->groupBox2->Controls->Add(this->button11);
			this->groupBox2->Controls->Add(this->button10);
			this->groupBox2->Controls->Add(this->button9);
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Location = System::Drawing::Point(26, 276);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(367, 330);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Konsola PC";
			// 
			// button34
			// 
			this->button34->Location = System::Drawing::Point(257, 274);
			this->button34->Name = L"button34";
			this->button34->Size = System::Drawing::Size(66, 26);
			this->button34->TabIndex = 26;
			this->button34->Text = L"LF";
			this->button34->UseVisualStyleBackColor = true;
			this->button34->Click += gcnew System::EventHandler(this, &Form1::button34_Click);
			// 
			// button33
			// 
			this->button33->Location = System::Drawing::Point(185, 274);
			this->button33->Name = L"button33";
			this->button33->Size = System::Drawing::Size(66, 26);
			this->button33->TabIndex = 25;
			this->button33->Text = L"CR";
			this->button33->UseVisualStyleBackColor = true;
			this->button33->Click += gcnew System::EventHandler(this, &Form1::button33_Click);
			// 
			// button32
			// 
			this->button32->Location = System::Drawing::Point(148, 274);
			this->button32->Name = L"button32";
			this->button32->Size = System::Drawing::Size(30, 26);
			this->button32->TabIndex = 24;
			this->button32->Text = L"+";
			this->button32->UseVisualStyleBackColor = true;
			this->button32->Click += gcnew System::EventHandler(this, &Form1::button32_Click);
			// 
			// button31
			// 
			this->button31->Location = System::Drawing::Point(112, 274);
			this->button31->Name = L"button31";
			this->button31->Size = System::Drawing::Size(30, 26);
			this->button31->TabIndex = 23;
			this->button31->Text = L"-";
			this->button31->UseVisualStyleBackColor = true;
			this->button31->Click += gcnew System::EventHandler(this, &Form1::button31_Click);
			// 
			// button30
			// 
			this->button30->Location = System::Drawing::Point(76, 274);
			this->button30->Name = L"button30";
			this->button30->Size = System::Drawing::Size(30, 26);
			this->button30->TabIndex = 22;
			this->button30->Text = L"#";
			this->button30->UseVisualStyleBackColor = true;
			this->button30->Click += gcnew System::EventHandler(this, &Form1::button30_Click);
			// 
			// button29
			// 
			this->button29->Location = System::Drawing::Point(40, 274);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(30, 26);
			this->button29->TabIndex = 21;
			this->button29->Text = L":";
			this->button29->UseVisualStyleBackColor = true;
			this->button29->Click += gcnew System::EventHandler(this, &Form1::button29_Click);
			// 
			// button28
			// 
			this->button28->Location = System::Drawing::Point(293, 242);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(30, 26);
			this->button28->TabIndex = 20;
			this->button28->Text = L"F";
			this->button28->UseVisualStyleBackColor = true;
			this->button28->Click += gcnew System::EventHandler(this, &Form1::button28_Click);
			// 
			// button27
			// 
			this->button27->Location = System::Drawing::Point(257, 242);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(30, 26);
			this->button27->TabIndex = 19;
			this->button27->Text = L"E";
			this->button27->UseVisualStyleBackColor = true;
			this->button27->Click += gcnew System::EventHandler(this, &Form1::button27_Click);
			// 
			// button26
			// 
			this->button26->Location = System::Drawing::Point(221, 242);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(30, 26);
			this->button26->TabIndex = 18;
			this->button26->Text = L"D";
			this->button26->UseVisualStyleBackColor = true;
			this->button26->Click += gcnew System::EventHandler(this, &Form1::button26_Click);
			// 
			// button25
			// 
			this->button25->Location = System::Drawing::Point(185, 242);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(30, 26);
			this->button25->TabIndex = 17;
			this->button25->Text = L"C";
			this->button25->UseVisualStyleBackColor = true;
			this->button25->Click += gcnew System::EventHandler(this, &Form1::button25_Click);
			// 
			// button24
			// 
			this->button24->Location = System::Drawing::Point(148, 242);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(30, 26);
			this->button24->TabIndex = 16;
			this->button24->Text = L"B";
			this->button24->UseVisualStyleBackColor = true;
			this->button24->Click += gcnew System::EventHandler(this, &Form1::button24_Click);
			// 
			// button23
			// 
			this->button23->Location = System::Drawing::Point(112, 242);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(30, 26);
			this->button23->TabIndex = 15;
			this->button23->Text = L"A";
			this->button23->UseVisualStyleBackColor = true;
			this->button23->Click += gcnew System::EventHandler(this, &Form1::button23_Click);
			// 
			// button22
			// 
			this->button22->Location = System::Drawing::Point(76, 242);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(30, 26);
			this->button22->TabIndex = 14;
			this->button22->Text = L"9";
			this->button22->UseVisualStyleBackColor = true;
			this->button22->Click += gcnew System::EventHandler(this, &Form1::button22_Click);
			// 
			// button21
			// 
			this->button21->Location = System::Drawing::Point(40, 242);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(30, 26);
			this->button21->TabIndex = 13;
			this->button21->Text = L"8";
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Click += gcnew System::EventHandler(this, &Form1::button21_Click);
			// 
			// button20
			// 
			this->button20->Location = System::Drawing::Point(293, 210);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(30, 26);
			this->button20->TabIndex = 12;
			this->button20->Text = L"7";
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &Form1::button20_Click);
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(257, 210);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(30, 26);
			this->button19->TabIndex = 11;
			this->button19->Text = L"6";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &Form1::button19_Click);
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(221, 210);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(30, 26);
			this->button18->TabIndex = 10;
			this->button18->Text = L"5";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &Form1::button18_Click);
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(185, 210);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(30, 26);
			this->button17->TabIndex = 9;
			this->button17->Text = L"4";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &Form1::button17_Click);
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(148, 210);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(30, 26);
			this->button16->TabIndex = 8;
			this->button16->Text = L"3";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &Form1::button16_Click);
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(112, 210);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(30, 26);
			this->button15->TabIndex = 7;
			this->button15->Text = L"2";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &Form1::button15_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(76, 210);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(30, 26);
			this->button14->TabIndex = 6;
			this->button14->Text = L"1";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &Form1::button14_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(40, 210);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(30, 26);
			this->button13->TabIndex = 5;
			this->button13->Text = L"0";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &Form1::button13_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(257, 158);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(66, 36);
			this->button12->TabIndex = 4;
			this->button12->Text = L"F4";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &Form1::button12_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(185, 158);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(66, 36);
			this->button11->TabIndex = 3;
			this->button11->Text = L"F3";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(112, 158);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(66, 36);
			this->button10->TabIndex = 2;
			this->button10->Text = L"F2";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(40, 158);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(66, 36);
			this->button9->TabIndex = 1;
			this->button9->Text = L"F1";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(40, 33);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(280, 108);
			this->textBox3->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1;
			this->timer2->Tick += gcnew System::EventHandler(this, &Form1::timer2_Tick);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->textBox13);
			this->groupBox3->Controls->Add(this->textBox12);
			this->groupBox3->Controls->Add(this->textBox11);
			this->groupBox3->Controls->Add(this->textBox10);
			this->groupBox3->Controls->Add(this->textBox9);
			this->groupBox3->Controls->Add(this->textBox8);
			this->groupBox3->Controls->Add(this->textBox7);
			this->groupBox3->Controls->Add(this->textBox6);
			this->groupBox3->Controls->Add(this->textBox5);
			this->groupBox3->Controls->Add(this->textBox4);
			this->groupBox3->Controls->Add(this->pictureBox1);
			this->groupBox3->Location = System::Drawing::Point(426, 41);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(470, 442);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Obiekt";
			// 
			// textBox13
			// 
			this->textBox13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox13->Enabled = false;
			this->textBox13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->textBox13->Location = System::Drawing::Point(59, 293);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(46, 26);
			this->textBox13->TabIndex = 10;
			this->textBox13->Text = L"0";
			this->textBox13->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textBox12
			// 
			this->textBox12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox12->Enabled = false;
			this->textBox12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->textBox12->Location = System::Drawing::Point(59, 151);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(46, 26);
			this->textBox12->TabIndex = 9;
			this->textBox12->Text = L"0";
			this->textBox12->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textBox11
			// 
			this->textBox11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox11->Enabled = false;
			this->textBox11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->textBox11->Location = System::Drawing::Point(59, 249);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(28, 20);
			this->textBox11->TabIndex = 8;
			this->textBox11->Text = L"TM";
			this->textBox11->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox10
			// 
			this->textBox10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox10->Enabled = false;
			this->textBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->textBox10->Location = System::Drawing::Point(181, 383);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(28, 20);
			this->textBox10->TabIndex = 7;
			this->textBox10->Text = L"GR";
			this->textBox10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox9
			// 
			this->textBox9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox9->Enabled = false;
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->textBox9->Location = System::Drawing::Point(373, 175);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(28, 20);
			this->textBox9->TabIndex = 6;
			this->textBox9->Text = L"X3";
			this->textBox9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox8
			// 
			this->textBox8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox8->Enabled = false;
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->textBox8->Location = System::Drawing::Point(373, 221);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(28, 20);
			this->textBox8->TabIndex = 5;
			this->textBox8->Text = L"X2";
			this->textBox8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox7
			// 
			this->textBox7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox7->Enabled = false;
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->textBox7->Location = System::Drawing::Point(373, 270);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(28, 20);
			this->textBox7->TabIndex = 4;
			this->textBox7->Text = L"X1";
			this->textBox7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox6->Enabled = false;
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->textBox6->Location = System::Drawing::Point(313, 377);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(28, 20);
			this->textBox6->TabIndex = 3;
			this->textBox6->Text = L"Z3";
			this->textBox6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox5->Enabled = false;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->textBox5->Location = System::Drawing::Point(315, 66);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(28, 20);
			this->textBox5->TabIndex = 2;
			this->textBox5->Text = L"Z2";
			this->textBox5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->textBox4->Enabled = false;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->textBox4->Location = System::Drawing::Point(98, 65);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(28, 20);
			this->textBox4->TabIndex = 1;
			this->textBox4->Text = L"Z1";
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(22, 29);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(420, 400);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->textBox15);
			this->groupBox4->Controls->Add(this->textBox14);
			this->groupBox4->Location = System::Drawing::Point(426, 499);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(469, 106);
			this->groupBox4->TabIndex = 3;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Komunikacja";
			// 
			// textBox15
			// 
			this->textBox15->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox15->Enabled = false;
			this->textBox15->Location = System::Drawing::Point(255, 19);
			this->textBox15->Multiline = true;
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(187, 81);
			this->textBox15->TabIndex = 4;
			// 
			// textBox14
			// 
			this->textBox14->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox14->Enabled = false;
			this->textBox14->Location = System::Drawing::Point(22, 19);
			this->textBox14->Multiline = true;
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(187, 81);
			this->textBox14->TabIndex = 1;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(934, 635);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 aK1=!aK1;
 			 if (aK1)  this->button5->BackColor = System::Drawing::SystemColors::ControlDark;
			 else      this->button5->BackColor = System::Drawing::SystemColors::Control;
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 aK2=!aK2;
 			 if (aK2)  this->button6->BackColor = System::Drawing::SystemColors::ControlDark;
			 else      this->button6->BackColor = System::Drawing::SystemColors::Control;
		 }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 aK3=!aK3;
 			 if (aK3)  this->button7->BackColor = System::Drawing::SystemColors::ControlDark;
			 else      this->button7->BackColor = System::Drawing::SystemColors::Control;
		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			 aK4=!aK4;
 			 if (aK4)  this->button8->BackColor = System::Drawing::SystemColors::ControlDark;
			 else      this->button8->BackColor = System::Drawing::SystemColors::Control;
		 }


private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {			 

			 System::String^ ln; System::Char cc; int ii;

			 if (fl_ini) { inicjuj(); cc_znak=0;  fl_ini=0; }

			 // ------------------ symulacja obiektu -----------------------

			 // sym_Z1=1; sym_GR=1;

			 if (sym_Z1) wlvl+=3; if (sym_Z2) wlvl+=2; if (sym_Z3) wlvl-=4;
			 if (wlvl<0) wlvl=0; else if (wlvl>1000) wlvl=1000;
			 sym_X1=wlvl>200;  sym_X2=wlvl>500; sym_X3=wlvl>800;

			 if (sym_GR) temp+=3; else temp-=5; 
			 if (temp<0) temp=0; else if (temp>800) temp=800;
			 sym_TM=temp>600;

			 sym_trans_char(cc=':');           ln=cc.ToString(); this->textBox15->AppendText(ln);
			 sym_trans_char(cc=sym_X1+'0');    ln=cc.ToString(); this->textBox15->AppendText(ln);
			 sym_trans_char(cc=sym_X2+'0');    ln=cc.ToString(); this->textBox15->AppendText(ln);
			 sym_trans_char(cc=sym_X3+'0');    ln=cc.ToString(); this->textBox15->AppendText(ln);
			 sym_trans_char(cc=sym_TM+'0');    ln=cc.ToString(); this->textBox15->AppendText(ln);
			 sym_trans_char(cc='\r');          ln=cc.ToString(); this->textBox15->AppendText(ln);
			 sym_trans_char(cc='\n');          ln=cc.ToString(); this->textBox15->AppendText(ln);


			 if (sym_X1) this->textBox7->BackColor = System::Drawing::Color::Yellow;
			 else        this->textBox7->BackColor = System::Drawing::Color::White;
			 if (sym_X2) this->textBox8->BackColor = System::Drawing::Color::Yellow;
			 else        this->textBox8->BackColor = System::Drawing::Color::White;
			 if (sym_X3) this->textBox9->BackColor = System::Drawing::Color::Yellow;
			 else        this->textBox9->BackColor = System::Drawing::Color::White;
			 if (sym_TM) this->textBox11->BackColor = System::Drawing::Color::Yellow;
			 else        this->textBox11->BackColor = System::Drawing::Color::White;

 			 if (sym_Z1) this->textBox4->BackColor = System::Drawing::Color::LightGreen;
			 else        this->textBox4->BackColor = System::Drawing::Color::White;
			 if (sym_Z2) this->textBox5->BackColor = System::Drawing::Color::LightGreen;
			 else        this->textBox5->BackColor = System::Drawing::Color::White;
			 if (sym_Z3) this->textBox6->BackColor = System::Drawing::Color::LightGreen;
			 else        this->textBox6->BackColor = System::Drawing::Color::White;
			 if (sym_GR) this->textBox10->BackColor = System::Drawing::Color::LightGreen;
			 else        this->textBox10->BackColor = System::Drawing::Color::White;

			 this->textBox12->Clear(); ln=""; ln=wlvl.ToString();
			 this->textBox12->AppendText(ln);
			 if (wlvl>=950)  this->textBox12->BackColor = System::Drawing::Color::Red;
			 else            this->textBox12->BackColor = System::Drawing::Color::LightYellow;

			 this->textBox13->Clear(); ln=""; ii=20+temp/10; ln=ii.ToString();
			 this->textBox13->AppendText(ln);
			 if (temp>=700) this->textBox13->BackColor = System::Drawing::Color::Red;
			 else           this->textBox13->BackColor = System::Drawing::Color::LightYellow;

			 // ------------------ regulator -------------------------------

			 oblicz();

			 //------------------- obs³uga LEDów ---------------------------
			 if (L1)  this->button1->BackColor = System::Drawing::Color::Red;
			 else     this->button1->BackColor = System::Drawing::SystemColors::Control;
			 if (L2)  this->button2->BackColor = System::Drawing::Color::Red;
			 else     this->button2->BackColor = System::Drawing::SystemColors::Control;
			 if (L3)  this->button3->BackColor = System::Drawing::Color::Red;
			 else     this->button3->BackColor = System::Drawing::SystemColors::Control;
			 if (L4)  this->button4->BackColor = System::Drawing::Color::Red;
			 else     this->button4->BackColor = System::Drawing::SystemColors::Control;

			 // ------------------ obs³uga LCD ----------------------------

			 this->textBox1->Clear(); ln="";
			 for(int i=0; i<20; ++i) { cc=line1[i]; ln+=cc.ToString(); }
			 this->textBox1->AppendText(ln);

			 this->textBox2->Clear(); ln="";
			 for(int i=0; i<20; ++i) { cc=line2[i]; ln+=cc.ToString(); }
			 this->textBox2->AppendText(ln);
		 }



private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
			 System::String^ ln; System::Char cc;

			 if (fl_nad==0)
			 {
				 if (buf_ind1!=buf_ind2)
				 {
				   ++buf_ind1; buf_ind1&=0x00FF; cc=buf_nad[buf_ind1];
				   ln=cc.ToString(); this->textBox3->AppendText(ln);
				   cx_znak=0;
				 }
			 }

			 if (fl_sym==0)
			 {
				 if (sym_ind1!=sym_ind2)
				 {
				   char znak;

				   ++sym_ind1; sym_ind1&=0x00FF; cc=buf_sym[sym_ind1];
				   ln=cc.ToString(); this->textBox14->AppendText(ln);
				   rc_sym=0;

				   znak=cc;
				   	switch(stan_z) {
						case 1: if (znak==':') stan_z=2; else stan_z=1;      // znak ':'
								break;
						case 2: if (znak=='1') { stan_z=3; sym_Z1=1; }  
								else
								if (znak=='0') { stan_z=3; sym_Z1=0; }  
								else 
									stan_z=1;                 // b³ad - szukaj od poczatku
								break;
						case 3: if (znak=='1') { stan_z=4; sym_Z2=1; }  
								else
								if (znak=='0') { stan_z=4; sym_Z2=0; }  
								else 
					 				stan_z=1;                 // b³ad - szukaj od poczatku
								break;
						case 4: if (znak=='1') { stan_z=5; sym_Z3=1; }  
								else
								if (znak=='0') { stan_z=5; sym_Z3=0; }  
								else 
					 				stan_z=1;                 // b³ad - szukaj od poczatku
								break;
						case 5: if (znak=='1') { stan_z=1; sym_GR=1; }  
								else
								if (znak=='0') { stan_z=1; sym_GR=0; }  
								else 
					 				stan_z=1;                 // b³ad - szukaj od poczatku
								break;
					}
				 }
			 }
		 }


private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
			 cc_znak='0';  int_znak();
		 }
private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
			 cc_znak='1';  int_znak();
		 }
private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {
 			 cc_znak='2';  int_znak();
		 }
private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) {
 			 cc_znak='3';  int_znak();
		 }
private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
 			 cc_znak='4';  int_znak();
		 }
private: System::Void button18_Click(System::Object^  sender, System::EventArgs^  e) {
 			 cc_znak='5';  int_znak();
		 }
private: System::Void button19_Click(System::Object^  sender, System::EventArgs^  e) {
 			 cc_znak='6';  int_znak();
		 }
private: System::Void button20_Click(System::Object^  sender, System::EventArgs^  e) {
 			 cc_znak='7';  int_znak();
		 }
private: System::Void button21_Click(System::Object^  sender, System::EventArgs^  e) {
 			 cc_znak='8';  int_znak();
		 }
private: System::Void button22_Click(System::Object^  sender, System::EventArgs^  e) {
 			 cc_znak='9';  int_znak();
		 }
private: System::Void button23_Click(System::Object^  sender, System::EventArgs^  e) {
 			 cc_znak='A';  int_znak();
		 }
private: System::Void button24_Click(System::Object^  sender, System::EventArgs^  e) {
 			 cc_znak='B';  int_znak();
		 }
private: System::Void button25_Click(System::Object^  sender, System::EventArgs^  e) {
 			 cc_znak='C';  int_znak();
		 }
private: System::Void button26_Click(System::Object^  sender, System::EventArgs^  e) {
 			 cc_znak='D';  int_znak();
		 }
private: System::Void button27_Click(System::Object^  sender, System::EventArgs^  e) {
 			 cc_znak='E';  int_znak();
		 }
private: System::Void button28_Click(System::Object^  sender, System::EventArgs^  e) {
 			 cc_znak='F';  int_znak();
		 }
private: System::Void button29_Click(System::Object^  sender, System::EventArgs^  e) {
			 cc_znak=':';  int_znak();
		 }
private: System::Void button30_Click(System::Object^  sender, System::EventArgs^  e) {
			 cc_znak='#';  int_znak();
		 }
private: System::Void button31_Click(System::Object^  sender, System::EventArgs^  e) {
 			 cc_znak='-';  int_znak();
		 }
private: System::Void button32_Click(System::Object^  sender, System::EventArgs^  e) {
 			 cc_znak='+';  int_znak();
		 }
private: System::Void button33_Click(System::Object^  sender, System::EventArgs^  e) {
 			 cc_znak=0x0D;  int_znak();
		 }
private: System::Void button34_Click(System::Object^  sender, System::EventArgs^  e) {
 			 cc_znak=0x0A;  int_znak();
		 }

private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			 klaw_F1();
		 }
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
			 klaw_F2();
		 }
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
			 klaw_F3();
		 }
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
			 klaw_F4();
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 wlvl=temp=0; sym_X1=sym_X2=sym_X3=sym_TM=sym_Z1=sym_Z2=sym_Z3=sym_GR=0;
			 stan_z=1;
		 }
};
}

