#pragma once
#include "TQueue.h"

namespace QueueVisualInterface {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	TQueue<int> queue;
	int maxSize = 0;
	int size = 0;
	int initialSize = 0;
	double addChance = 0;
	double remChance = 0;
	int pushed = 0;
	int popped = 0;
	int tickrate = 0;

	public ref class QueueVisualInterface : public System::Windows::Forms::Form
	{
	private:

	public:
		QueueVisualInterface(void)
		{
			InitializeComponent();
		}

	protected:
		~QueueVisualInterface()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Random^ rand;
	public: Graphics^ gr;
	public: System::Drawing::Rectangle rect;

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ labelQueSize;
	private: System::Windows::Forms::TrackBar^ QAddChanceTrackBar;


	private: System::Windows::Forms::TextBox^ QSizeBox;
	private: System::Windows::Forms::TextBox^ QAmountBox;
	private: System::Windows::Forms::Label^ labelInitElems;

	private: System::Windows::Forms::Label^ labelAddChance;

	private: System::Windows::Forms::Label^ labelRemoveChance;
	private: System::Windows::Forms::TrackBar^ QRemChanceTrackBar;

	private: System::Windows::Forms::Label^ labelTickrate;
	private: System::Windows::Forms::TextBox^ QFreqBox;
	private: System::Windows::Forms::Button^ StartButton;

	private: System::Windows::Forms::Button^ StopButton;

	private: System::Windows::Forms::Label^ ErrorLabelSize;
	private: System::Windows::Forms::Label^ ErrorLabelAmount;


	private: System::Windows::Forms::Label^ ErrorLabelFreq;	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Label^ RemDoubleLabel;
	private: System::Windows::Forms::CheckBox^ checkBox1;

	private: System::Windows::Forms::Label^ AddDoubleLabel;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Label^ labelPoppedElems;
	private: System::Windows::Forms::Label^ labelPushedElems;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ CurSizeLabel;
	private: System::Windows::Forms::Label^ PushedLabel;
	private: System::Windows::Forms::Label^ PoppedLabel;


	private:

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->labelQueSize = (gcnew System::Windows::Forms::Label());
			this->QAddChanceTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->QSizeBox = (gcnew System::Windows::Forms::TextBox());
			this->QAmountBox = (gcnew System::Windows::Forms::TextBox());
			this->labelInitElems = (gcnew System::Windows::Forms::Label());
			this->labelAddChance = (gcnew System::Windows::Forms::Label());
			this->labelRemoveChance = (gcnew System::Windows::Forms::Label());
			this->QRemChanceTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->labelTickrate = (gcnew System::Windows::Forms::Label());
			this->QFreqBox = (gcnew System::Windows::Forms::TextBox());
			this->StartButton = (gcnew System::Windows::Forms::Button());
			this->StopButton = (gcnew System::Windows::Forms::Button());
			this->ErrorLabelSize = (gcnew System::Windows::Forms::Label());
			this->ErrorLabelAmount = (gcnew System::Windows::Forms::Label());
			this->ErrorLabelFreq = (gcnew System::Windows::Forms::Label());
			this->RemDoubleLabel = (gcnew System::Windows::Forms::Label());
			this->AddDoubleLabel = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->labelPoppedElems = (gcnew System::Windows::Forms::Label());
			this->labelPushedElems = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->CurSizeLabel = (gcnew System::Windows::Forms::Label());
			this->PushedLabel = (gcnew System::Windows::Forms::Label());
			this->PoppedLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->QAddChanceTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->QRemChanceTrackBar))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &QueueVisualInterface::timer1_Tick);
			// 
			// labelQueSize
			// 
			this->labelQueSize->AutoSize = true;
			this->labelQueSize->Location = System::Drawing::Point(90, 20);
			this->labelQueSize->Name = L"labelQueSize";
			this->labelQueSize->Size = System::Drawing::Size(66, 13);
			this->labelQueSize->TabIndex = 0;
			this->labelQueSize->Text = L"Queue size: ";
			// 
			// QAddChanceTrackBar
			// 
			this->QAddChanceTrackBar->Location = System::Drawing::Point(151, 69);
			this->QAddChanceTrackBar->Maximum = 100;
			this->QAddChanceTrackBar->Name = L"QAddChanceTrackBar";
			this->QAddChanceTrackBar->Size = System::Drawing::Size(111, 45);
			this->QAddChanceTrackBar->TabIndex = 1;
			this->QAddChanceTrackBar->Scroll += gcnew System::EventHandler(this, &QueueVisualInterface::QAddChanceTrackBar_Scroll);
			// 
			// QSizeBox
			// 
			this->QSizeBox->Location = System::Drawing::Point(155, 17);
			this->QSizeBox->Name = L"QSizeBox";
			this->QSizeBox->Size = System::Drawing::Size(100, 20);
			this->QSizeBox->TabIndex = 2;
			// 
			// QAmountBox
			// 
			this->QAmountBox->Location = System::Drawing::Point(155, 43);
			this->QAmountBox->Name = L"QAmountBox";
			this->QAmountBox->Size = System::Drawing::Size(100, 20);
			this->QAmountBox->TabIndex = 4;
			// 
			// labelInitElems
			// 
			this->labelInitElems->AutoSize = true;
			this->labelInitElems->Location = System::Drawing::Point(23, 46);
			this->labelInitElems->Name = L"labelInitElems";
			this->labelInitElems->Size = System::Drawing::Size(132, 13);
			this->labelInitElems->TabIndex = 3;
			this->labelInitElems->Text = L"Initial amount of elements: ";
			// 
			// labelAddChance
			// 
			this->labelAddChance->AutoSize = true;
			this->labelAddChance->Location = System::Drawing::Point(20, 72);
			this->labelAddChance->Name = L"labelAddChance";
			this->labelAddChance->Size = System::Drawing::Size(138, 13);
			this->labelAddChance->TabIndex = 5;
			this->labelAddChance->Text = L"Chance to add an element: ";
			// 
			// labelRemoveChance
			// 
			this->labelRemoveChance->AutoSize = true;
			this->labelRemoveChance->Location = System::Drawing::Point(0, 114);
			this->labelRemoveChance->Name = L"labelRemoveChance";
			this->labelRemoveChance->Size = System::Drawing::Size(155, 13);
			this->labelRemoveChance->TabIndex = 7;
			this->labelRemoveChance->Text = L"Chance to remove an element: ";
			// 
			// QRemChanceTrackBar
			// 
			this->QRemChanceTrackBar->Location = System::Drawing::Point(151, 107);
			this->QRemChanceTrackBar->Maximum = 100;
			this->QRemChanceTrackBar->Name = L"QRemChanceTrackBar";
			this->QRemChanceTrackBar->Size = System::Drawing::Size(111, 45);
			this->QRemChanceTrackBar->TabIndex = 8;
			this->QRemChanceTrackBar->Scroll += gcnew System::EventHandler(this, &QueueVisualInterface::QRemChanceTrackBar_Scroll);
			// 
			// labelTickrate
			// 
			this->labelTickrate->AutoSize = true;
			this->labelTickrate->Location = System::Drawing::Point(105, 151);
			this->labelTickrate->Name = L"labelTickrate";
			this->labelTickrate->Size = System::Drawing::Size(52, 13);
			this->labelTickrate->TabIndex = 9;
			this->labelTickrate->Text = L"Tickrate: ";
			// 
			// QFreqBox
			// 
			this->QFreqBox->Location = System::Drawing::Point(155, 148);
			this->QFreqBox->Name = L"QFreqBox";
			this->QFreqBox->Size = System::Drawing::Size(100, 20);
			this->QFreqBox->TabIndex = 10;
			// 
			// StartButton
			// 
			this->StartButton->Location = System::Drawing::Point(86, 191);
			this->StartButton->Name = L"StartButton";
			this->StartButton->Size = System::Drawing::Size(75, 23);
			this->StartButton->TabIndex = 11;
			this->StartButton->Text = L"Start";
			this->StartButton->UseVisualStyleBackColor = true;
			this->StartButton->Click += gcnew System::EventHandler(this, &QueueVisualInterface::StartButton_Click);
			// 
			// StopButton
			// 
			this->StopButton->Enabled = false;
			this->StopButton->Location = System::Drawing::Point(200, 191);
			this->StopButton->Name = L"StopButton";
			this->StopButton->Size = System::Drawing::Size(75, 23);
			this->StopButton->TabIndex = 12;
			this->StopButton->Text = L"Stop";
			this->StopButton->UseVisualStyleBackColor = true;
			this->StopButton->Click += gcnew System::EventHandler(this, &QueueVisualInterface::StopButton_Click);
			// 
			// ErrorLabelSize
			// 
			this->ErrorLabelSize->AutoSize = true;
			this->ErrorLabelSize->ForeColor = System::Drawing::Color::Brown;
			this->ErrorLabelSize->Location = System::Drawing::Point(271, 20);
			this->ErrorLabelSize->Name = L"ErrorLabelSize";
			this->ErrorLabelSize->Size = System::Drawing::Size(56, 13);
			this->ErrorLabelSize->TabIndex = 13;
			this->ErrorLabelSize->Text = L"Input Error";
			this->ErrorLabelSize->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->ErrorLabelSize->Visible = false;
			// 
			// ErrorLabelAmount
			// 
			this->ErrorLabelAmount->AutoSize = true;
			this->ErrorLabelAmount->ForeColor = System::Drawing::Color::Brown;
			this->ErrorLabelAmount->Location = System::Drawing::Point(271, 46);
			this->ErrorLabelAmount->Name = L"ErrorLabelAmount";
			this->ErrorLabelAmount->Size = System::Drawing::Size(56, 13);
			this->ErrorLabelAmount->TabIndex = 14;
			this->ErrorLabelAmount->Text = L"Input Error";
			this->ErrorLabelAmount->Visible = false;
			// 
			// ErrorLabelFreq
			// 
			this->ErrorLabelFreq->AutoSize = true;
			this->ErrorLabelFreq->ForeColor = System::Drawing::Color::Brown;
			this->ErrorLabelFreq->Location = System::Drawing::Point(271, 151);
			this->ErrorLabelFreq->Name = L"ErrorLabelFreq";
			this->ErrorLabelFreq->Size = System::Drawing::Size(56, 13);
			this->ErrorLabelFreq->TabIndex = 17;
			this->ErrorLabelFreq->Text = L"Input Error";
			this->ErrorLabelFreq->Visible = false;
			// 
			// RemDoubleLabel
			// 
			this->RemDoubleLabel->AutoSize = true;
			this->RemDoubleLabel->Location = System::Drawing::Point(278, 114);
			this->RemDoubleLabel->Name = L"RemDoubleLabel";
			this->RemDoubleLabel->Size = System::Drawing::Size(28, 13);
			this->RemDoubleLabel->TabIndex = 1;
			this->RemDoubleLabel->Text = L"0.00";
			// 
			// AddDoubleLabel
			// 
			this->AddDoubleLabel->AutoSize = true;
			this->AddDoubleLabel->Location = System::Drawing::Point(278, 83);
			this->AddDoubleLabel->Name = L"AddDoubleLabel";
			this->AddDoubleLabel->Size = System::Drawing::Size(28, 13);
			this->AddDoubleLabel->TabIndex = 0;
			this->AddDoubleLabel->Text = L"0.00";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(30, 250);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(14, 13);
			this->radioButton1->TabIndex = 18;
			this->radioButton1->TabStop = true;
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->Visible = false;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(330, 250);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(14, 13);
			this->radioButton2->TabIndex = 19;
			this->radioButton2->TabStop = true;
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->Visible = false;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(330, 550);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(14, 13);
			this->radioButton3->TabIndex = 20;
			this->radioButton3->TabStop = true;
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->Visible = false;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(30, 550);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(14, 13);
			this->radioButton4->TabIndex = 21;
			this->radioButton4->TabStop = true;
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->Visible = false;
			// 
			// labelPoppedElems
			// 
			this->labelPoppedElems->AutoSize = true;
			this->labelPoppedElems->Location = System::Drawing::Point(120, 383);
			this->labelPoppedElems->Name = L"labelPoppedElems";
			this->labelPoppedElems->Size = System::Drawing::Size(95, 13);
			this->labelPoppedElems->TabIndex = 22;
			this->labelPoppedElems->Text = L"Elements popped: ";
			// 
			// labelPushedElems
			// 
			this->labelPushedElems->AutoSize = true;
			this->labelPushedElems->Location = System::Drawing::Point(120, 410);
			this->labelPushedElems->Name = L"labelPushedElems";
			this->labelPushedElems->Size = System::Drawing::Size(94, 13);
			this->labelPushedElems->TabIndex = 23;
			this->labelPushedElems->Text = L"Elements pushed: ";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(130, 355);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(68, 13);
			this->label8->TabIndex = 24;
			this->label8->Text = L"Current size: ";
			// 
			// CurSizeLabel
			// 
			this->CurSizeLabel->AutoSize = true;
			this->CurSizeLabel->Location = System::Drawing::Point(211, 355);
			this->CurSizeLabel->Name = L"CurSizeLabel";
			this->CurSizeLabel->Size = System::Drawing::Size(13, 13);
			this->CurSizeLabel->TabIndex = 27;
			this->CurSizeLabel->Text = L"0";
			// 
			// PushedLabel
			// 
			this->PushedLabel->AutoSize = true;
			this->PushedLabel->Location = System::Drawing::Point(211, 410);
			this->PushedLabel->Name = L"PushedLabel";
			this->PushedLabel->Size = System::Drawing::Size(13, 13);
			this->PushedLabel->TabIndex = 26;
			this->PushedLabel->Text = L"0";
			// 
			// PoppedLabel
			// 
			this->PoppedLabel->AutoSize = true;
			this->PoppedLabel->Location = System::Drawing::Point(211, 383);
			this->PoppedLabel->Name = L"PoppedLabel";
			this->PoppedLabel->Size = System::Drawing::Size(13, 13);
			this->PoppedLabel->TabIndex = 25;
			this->PoppedLabel->Text = L"0";
			// 
			// QueueVisualInterface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(380, 578);
			this->Controls->Add(this->CurSizeLabel);
			this->Controls->Add(this->PushedLabel);
			this->Controls->Add(this->PoppedLabel);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->labelPushedElems);
			this->Controls->Add(this->labelPoppedElems);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->RemDoubleLabel);
			this->Controls->Add(this->AddDoubleLabel);
			this->Controls->Add(this->ErrorLabelFreq);
			this->Controls->Add(this->ErrorLabelAmount);
			this->Controls->Add(this->ErrorLabelSize);
			this->Controls->Add(this->StopButton);
			this->Controls->Add(this->StartButton);
			this->Controls->Add(this->QFreqBox);
			this->Controls->Add(this->labelTickrate);
			this->Controls->Add(this->QRemChanceTrackBar);
			this->Controls->Add(this->labelRemoveChance);
			this->Controls->Add(this->labelAddChance);
			this->Controls->Add(this->QAmountBox);
			this->Controls->Add(this->labelInitElems);
			this->Controls->Add(this->QSizeBox);
			this->Controls->Add(this->QAddChanceTrackBar);
			this->Controls->Add(this->labelQueSize);
			this->Name = L"QueueVisualInterface";
			this->Text = L"Queue Visual Interface";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &QueueVisualInterface::QueueVisual_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->QAddChanceTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->QRemChanceTrackBar))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (addChance > rand->NextDouble() && !queue.IsFull()) {
			queue.Push(1);
			PushedLabel->Text = Convert::ToString(Convert::ToInt32(PushedLabel->Text) + 1);
			CurSizeLabel->Text = Convert::ToString(Convert::ToInt32(CurSizeLabel->Text) + 1);

		}
		if (remChance > rand->NextDouble() && !queue.IsEmpty()) {
			queue.Get();
			PoppedLabel->Text = Convert::ToString(Convert::ToInt32(PoppedLabel->Text) + 1);
			CurSizeLabel->Text = Convert::ToString(Convert::ToInt32(CurSizeLabel->Text) - 1);
		}
		DrawQ();
	}
	private: System::Void StartButton_Click(System::Object^ sender, System::EventArgs^ e) {
		ErrorLabelAmount->Visible = false;
		ErrorLabelSize->Visible = false;
		ErrorLabelFreq->Visible = false;
		PoppedLabel->Text = L"0";
		PushedLabel->Text = L"0";

		try {
			rand = gcnew Random();
			tickrate = Convert::ToInt32(QFreqBox->Text);

			maxSize = Convert::ToInt32(QSizeBox->Text);
			initialSize = Convert::ToInt32(QAmountBox->Text);

			addChance = QAddChanceTrackBar->Value / 100.0;
			remChance = QRemChanceTrackBar->Value / 100.0;
			queue = TQueue<int>(maxSize);
			for (size_t i = 0; i < initialSize; i++)
			{
				queue.Push(0);
			}
			StartButton->Text = "Start";
			StartButton->Enabled = false;
			CurSizeLabel->Text = Convert::ToString(initialSize);
			DrawQ();
			timer1->Interval = tickrate;
			timer1->Enabled = true;
			StopButton->Enabled = true;
		}
		catch (...) {
			Int32 i;
			if (maxSize.GetTypeCode() != i.GetTypeCode()) ErrorLabelSize->Visible = true;
			if (initialSize.GetTypeCode() != i.GetTypeCode()) ErrorLabelAmount->Visible = true;
			if (tickrate.GetTypeCode() != i.GetTypeCode()) ErrorLabelFreq->Visible = true;
			if (maxSize <= 0) ErrorLabelSize->Visible = true;
			if (initialSize < 0) ErrorLabelAmount->Visible = true;
			if (initialSize > maxSize) ErrorLabelAmount->Visible = true;
			if (tickrate <= 0) ErrorLabelFreq->Visible = true;
		}

	}
		   void DrawQ() {
			   ErrorLabelAmount->Visible = false;
			   ErrorLabelSize->Visible = false;
			   ErrorLabelFreq->Visible = false;

			   float startAngle = 360 * ((float)queue.GetTop() / (float)maxSize);
			   float finishAngle = 360 * ((float)queue.GetSize() / (float)maxSize);

			   Pen^ whitePen = gcnew Pen(Color::Silver);
			   whitePen->Width = 17.0f;
			   gr->DrawEllipse(whitePen, rect);

			   Pen^ blackPen = gcnew Pen(Color::Black);
			   blackPen->Width = 15.0f;
			   rect = System::Drawing::Rectangle(30.0, 250.0, 300.0, 300.0);
			   gr->DrawArc(blackPen, rect, startAngle, finishAngle);
		   }
	private: System::Void StopButton_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = false;
		StartButton->Enabled = true;
		StartButton->Text = "Restart";
		StopButton->Enabled = false;
	}
	private: System::Void QueueVisual_Load(System::Object^ sender, System::EventArgs^ e) {
		gr = this->CreateGraphics();
		tickrate = 0;
		maxSize = 0;
		size = 0;
		initialSize = 0;
		addChance = 0;
		remChance = 0;
		Pen^ whitePen = gcnew Pen(Color::Silver);
		whitePen->Width = 17.0f;
		gr->DrawEllipse(whitePen, rect);
	}
	private: System::Void QAddChanceTrackBar_Scroll(System::Object^ sender, System::EventArgs^ e) {
		AddDoubleLabel->Text = Convert::ToString(QAddChanceTrackBar->Value / 100.0);
	}
	private: System::Void QRemChanceTrackBar_Scroll(System::Object^ sender, System::EventArgs^ e) {
		RemDoubleLabel->Text = Convert::ToString(QRemChanceTrackBar->Value / 100.0);
	}
	};
}
