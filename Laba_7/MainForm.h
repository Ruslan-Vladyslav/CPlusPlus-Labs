#pragma once
#include <stdexcept>
#include <iostream>
#include "header.h"

namespace Laba7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ text1;
	private: System::Windows::Forms::TextBox^ text2;
	private: System::Windows::Forms::TextBox^ text3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ B1;
	private: System::Windows::Forms::Button^ B2;
	private: System::Windows::Forms::Label^ Result;
	private: System::Windows::Forms::Label^ Error;
	private: System::Windows::Forms::Label^ label5;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->text1 = (gcnew System::Windows::Forms::TextBox());
			this->text2 = (gcnew System::Windows::Forms::TextBox());
			this->text3 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->B1 = (gcnew System::Windows::Forms::Button());
			this->B2 = (gcnew System::Windows::Forms::Button());
			this->Result = (gcnew System::Windows::Forms::Label());
			this->Error = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(31, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(723, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"This program calculates the scalar product of vectors of a given dimension";
			// 
			// text1
			// 
			this->text1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->text1->Location = System::Drawing::Point(44, 147);
			this->text1->MinimumSize = System::Drawing::Size(308, 30);
			this->text1->Name = L"text1";
			this->text1->Size = System::Drawing::Size(308, 27);
			this->text1->TabIndex = 1;
			// 
			// text2
			// 
			this->text2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->text2->Location = System::Drawing::Point(44, 236);
			this->text2->MinimumSize = System::Drawing::Size(308, 30);
			this->text2->Name = L"text2";
			this->text2->Size = System::Drawing::Size(308, 27);
			this->text2->TabIndex = 2;
			// 
			// text3
			// 
			this->text3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->text3->Location = System::Drawing::Point(44, 330);
			this->text3->MinimumSize = System::Drawing::Size(308, 30);
			this->text3->Name = L"text3";
			this->text3->Size = System::Drawing::Size(308, 27);
			this->text3->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(41, 115);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(153, 25);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Enter dimension";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(41, 199);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(245, 25);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Enter values of 1-st vector";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(41, 301);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(251, 25);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Enter values of 2-nd vector";
			// 
			// B1
			// 
			this->B1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->B1->Location = System::Drawing::Point(163, 427);
			this->B1->MinimumSize = System::Drawing::Size(200, 50);
			this->B1->Name = L"B1";
			this->B1->Size = System::Drawing::Size(200, 50);
			this->B1->TabIndex = 7;
			this->B1->Text = L"Perform";
			this->B1->UseVisualStyleBackColor = true;
			this->B1->Click += gcnew System::EventHandler(this, &MainForm::B1_Click);
			// 
			// B2
			// 
			this->B2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->B2->Location = System::Drawing::Point(483, 427);
			this->B2->MinimumSize = System::Drawing::Size(200, 50);
			this->B2->Name = L"B2";
			this->B2->Size = System::Drawing::Size(200, 50);
			this->B2->TabIndex = 8;
			this->B2->Text = L"Clear";
			this->B2->UseVisualStyleBackColor = true;
			this->B2->Click += gcnew System::EventHandler(this, &MainForm::B2_Click);
			// 
			// Result
			// 
			this->Result->AutoSize = true;
			this->Result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Result->Location = System::Drawing::Point(551, 263);
			this->Result->Name = L"Result";
			this->Result->Size = System::Drawing::Size(157, 22);
			this->Result->TabIndex = 9;
			this->Result->Text = L"Result will be here";
			// 
			// Error
			// 
			this->Error->AutoSize = true;
			this->Error->Location = System::Drawing::Point(551, 279);
			this->Error->Name = L"Error";
			this->Error->Size = System::Drawing::Size(0, 16);
			this->Error->TabIndex = 10;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(548, 211);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(90, 32);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Result";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->ClientSize = System::Drawing::Size(832, 505);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->Error);
			this->Controls->Add(this->Result);
			this->Controls->Add(this->B2);
			this->Controls->Add(this->B1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->text3);
			this->Controls->Add(this->text2);
			this->Controls->Add(this->text1);
			this->Controls->Add(this->label1);
			this->MinimumSize = System::Drawing::Size(850, 552);
			this->Name = L"MainForm";
			this->Text = L"Lab 7-8";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void B1_Click(System::Object^ sender, System::EventArgs^ e) {
		array<String^>^ v1;
		array<String^>^ v2;

		String^ size = text1->Text;
		String^ vector1 = text2->Text;
		String^ vector2 = text3->Text;

		try {
			if (String::IsNullOrEmpty(size) || String::IsNullOrEmpty(vector1) || String::IsNullOrEmpty(vector2)) {
					throw gcnew ArgumentException("Please enter values for all fields!");
			}

			v1 = vector1->Split(' ');
			v2 = vector2->Split(' ');

			int vectorSize = 0;

			if (!Int32::TryParse(size, vectorSize) || (vectorSize != 2 && vectorSize != 3)) {
				throw gcnew FormatException("The value shouldn't be 1 or more than 3!");
			}

			if (v1->Length != vectorSize || v2->Length != vectorSize) {
				throw gcnew ArgumentException("The number of elements does not match the vector size!");
			}

			Vector vec1(vectorSize);
			Vector vec2(vectorSize);

			for (int i = 0; i < vectorSize; i++) {
				int element1;
				if (!Int32::TryParse(v1[i], element1) || element1 < 0) {
					throw gcnew FormatException("Element of vector-1 has the wrong format or is negative. Input correctly!!");
				}
				vec1[i] = element1;
			}

			for (int i = 0; i < vectorSize; i++) {
				int element2;
				if (!Int32::TryParse(v2[i], element2) || element2 < 0) {
					throw gcnew FormatException("Element of vector-2 has the wrong format or is negative. Input correctly!");
				}
				vec2[i] = element2;
			}

			int scalarProduct = vec1.calculateDotProduct(vec2);

			Result->Text = "Scalar product: " + scalarProduct;
		}
		catch (FormatException^ ex) {
			Result->Text = "Result will be here";
			MessageBox::Show(ex->Message, "Error");
		}
		catch (ArgumentException^ ex) {
			Result->Text = "Result will be here";
			MessageBox::Show(ex->Message, "Error");
		}
		catch (Exception^ ex) {
			Result->Text = "Result will be here";
			MessageBox::Show(ex->Message, "Error");
		}
	}
	private: 
		System::Void B2_Click(System::Object^ sender, System::EventArgs^ e) {
			this->text1->Text = "";
			this->text2->Text = "";
			this->text3->Text = "";
			this->Result->Text = "Result will be here";
	}
};
}
