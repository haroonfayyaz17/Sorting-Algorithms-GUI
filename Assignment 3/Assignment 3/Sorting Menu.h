#include <fstream>
#include <msclr\marshal_cppstd.h>

#include <string>

#include "Sorting Algorithms.h"

#pragma once

namespace Assignment3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	/// <summary>
	/// Summary for SortingMenu
	/// </summary>
	public ref class SortingMenu : public System::Windows::Forms::Form
	{
		String ^inputFileName = "", ^fileDirectory = "";
		int *inputArr = NULL;
	public:
		SortingMenu(void)
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
		~SortingMenu()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^  btnChooseFile;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  cmbSortingType;




	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;


	private: System::Windows::Forms::Button^  btnGetResult;







	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ListBox^  lstUnsorted;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::ListBox^  lstSorted;
	private: System::Windows::Forms::Label^  label7;





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
			this->btnChooseFile = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cmbSortingType = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnGetResult = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->lstUnsorted = (gcnew System::Windows::Forms::ListBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->lstSorted = (gcnew System::Windows::Forms::ListBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnChooseFile
			// 
			this->btnChooseFile->AutoSize = true;
			this->btnChooseFile->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->btnChooseFile->BackColor = System::Drawing::Color::PeachPuff;
			this->btnChooseFile->Location = System::Drawing::Point(813, 110);
			this->btnChooseFile->Name = L"btnChooseFile";
			this->btnChooseFile->Size = System::Drawing::Size(164, 41);
			this->btnChooseFile->TabIndex = 0;
			this->btnChooseFile->Text = L"Choose File";
			this->btnChooseFile->UseVisualStyleBackColor = false;
			this->btnChooseFile->Click += gcnew System::EventHandler(this, &SortingMenu::btnChooseFile_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Castellar", 20.16F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label1->Location = System::Drawing::Point(634, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(502, 42);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Welcome To FASTSORT";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// cmbSortingType
			// 
			this->cmbSortingType->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->cmbSortingType->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->cmbSortingType->FormattingEnabled = true;
			this->cmbSortingType->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"Bubble Sort", L"Bucket Sort", L"Count Sort",
					L"Heap Sort", L"Insertion Sort", L"Merge Sort", L"Quick Sort", L"Radix Sort", L"Selection Sort"
			});
			this->cmbSortingType->Location = System::Drawing::Point(915, 192);
			this->cmbSortingType->Name = L"cmbSortingType";
			this->cmbSortingType->Size = System::Drawing::Size(246, 38);
			this->cmbSortingType->TabIndex = 1;
			this->cmbSortingType->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SortingMenu::cmbSortingType_KeyPress);
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(962, 1034);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 150);
			this->label2->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(711, 974);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 50);
			this->label3->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(484, 185);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(221, 50);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Sorting Algorithm";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// btnGetResult
			// 
			this->btnGetResult->AutoSize = true;
			this->btnGetResult->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->btnGetResult->BackColor = System::Drawing::Color::Tomato;
			this->btnGetResult->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnGetResult->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnGetResult->Location = System::Drawing::Point(1151, 258);
			this->btnGetResult->Name = L"btnGetResult";
			this->btnGetResult->Size = System::Drawing::Size(147, 41);
			this->btnGetResult->TabIndex = 2;
			this->btnGetResult->Text = L"Get Result";
			this->btnGetResult->UseVisualStyleBackColor = false;
			this->btnGetResult->Click += gcnew System::EventHandler(this, &SortingMenu::btnGetResult_Click);
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(0, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 60);
			this->label5->TabIndex = 9;
			// 
			// lstUnsorted
			// 
			this->lstUnsorted->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.944F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lstUnsorted->FormattingEnabled = true;
			this->lstUnsorted->ItemHeight = 22;
			this->lstUnsorted->Location = System::Drawing::Point(466, 375);
			this->lstUnsorted->Name = L"lstUnsorted";
			this->lstUnsorted->Size = System::Drawing::Size(325, 444);
			this->lstUnsorted->TabIndex = 6;
			this->lstUnsorted->TabStop = false;
			// 
			// label10
			// 
			this->label10->Location = System::Drawing::Point(461, 322);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(221, 50);
			this->label10->TabIndex = 7;
			this->label10->Text = L"Unsorted";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lstSorted
			// 
			this->lstSorted->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.944F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lstSorted->FormattingEnabled = true;
			this->lstSorted->ItemHeight = 22;
			this->lstSorted->Location = System::Drawing::Point(1060, 375);
			this->lstSorted->Name = L"lstSorted";
			this->lstSorted->Size = System::Drawing::Size(307, 444);
			this->lstSorted->TabIndex = 6;
			this->lstSorted->TabStop = false;
			// 
			// label7
			// 
			this->label7->Location = System::Drawing::Point(1055, 322);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(101, 50);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Sorted";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SortingMenu
			// 
			this->AcceptButton = this->btnGetResult;
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 30);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(1924, 1054);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->lstSorted);
			this->Controls->Add(this->lstUnsorted);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnChooseFile);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->cmbSortingType);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnGetResult);
			this->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.824F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->KeyPreview = true;
			this->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->Name = L"SortingMenu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FAST SORT";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnChooseFile_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
		msclr::interop::marshal_context context;


		openFileDialog1->InitialDirectory = "c:\\Documents";
		openFileDialog1->Filter = "txt files (*.txt)|*.txt";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->RestoreDirectory = true;

		try{


			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				//MessageBox::Show(openFileDialog1->FileName);
				inputFileName = openFileDialog1->FileName;
				System::IO::FileInfo ^fInfo = gcnew System::IO::FileInfo(openFileDialog1->FileName);
				fileDirectory = fInfo->DirectoryName;
				MessageBox::Show("File selected successfully");
			}
		}
		catch (Exception ^ex){
			MessageBox::Show(ex->Message);
		}
		catch (...){
			MessageBox::Show("An error occurred");
		}
	}

	public: bool readFile(int &count){
		msclr::interop::marshal_context context;
		try{

			if (inputFileName == ""){
				MessageBox::Show("No file Selected");
				return false;
			}
			string input = context.marshal_as<string>(inputFileName);
			ifstream indata(input);
			string str;
			while (getline(indata, str))
			{
				count++;
			}
			indata.close();
			if (inputArr != NULL)
				delete[]inputArr;
			inputArr = new int[count];
			indata.open(input);
			int c = 0;
			while (getline(indata, str))
			{
				String ^s = gcnew String(str.c_str());
				inputArr[c++] = Convert::ToInt32(s);
			}
			indata.close();
			MessageBox::Show("File Read Successful");
			return true;
		}
		catch (Exception ^ex){
			MessageBox::Show(ex->Message);

		}
		catch (...){
			MessageBox::Show("An error occurred");
		}
		return false;

	}

	private: System::Void btnGetResult_Click(System::Object^  sender, System::EventArgs^  e) {
		msclr::interop::marshal_context context;
		lstUnsorted->Items->Clear();
		lstSorted->Items->Clear();
		try{

			if (cmbSortingType->Text == "")
			{
				MessageBox::Show("No Sorting technique selected");
				return;
			}
			int count = 0;
			if (readFile(count))
			{
				MessageBox::Show(cmbSortingType->Text);
				SortingAlgorithms sorting;
				ofstream outdata(context.marshal_as<string>(fileDirectory) +"\\" + "sorted.txt");
				if (cmbSortingType->Text == "Insertion Sort")
				{
					for (int i = 0; i < count; i++)
					{
						lstUnsorted->Items->Add(Convert::ToString(inputArr[i]));
					}
					sorting.insertionSort(inputArr, count);
					for (int i = 0; i < count; i++)
					{
						outdata << context.marshal_as<string>(Convert::ToString(inputArr[i])) << "\n";
						lstSorted->Items->Add(Convert::ToString(inputArr[i]));
					}

				}
				else if (cmbSortingType->Text == "Bubble Sort")
				{

					for (int i = 0; i < count; i++)
					{
						lstUnsorted->Items->Add(Convert::ToString(inputArr[i]));
					}
					sorting.bubbleSort(inputArr, count);
					for (int i = 0; i < count; i++)
					{
						outdata << context.marshal_as<string>(Convert::ToString(inputArr[i])) << "\n";

						lstSorted->Items->Add(Convert::ToString(inputArr[i]));
					}

				}
				else if (cmbSortingType->Text == "Selection Sort")
				{
					for (int i = 0; i < count; i++)
					{
						lstUnsorted->Items->Add(Convert::ToString(inputArr[i]));
					}
					sorting.selectionSort(inputArr, count);
					for (int i = 0; i < count; i++)
					{
						outdata << context.marshal_as<string>(Convert::ToString(inputArr[i])) << "\n";

						lstSorted->Items->Add(Convert::ToString(inputArr[i]));
					}

				}
				else if (cmbSortingType->Text == "Merge Sort")
				{
					for (int i = 0; i < count; i++)
					{
						lstUnsorted->Items->Add(Convert::ToString(inputArr[i]));
					}
					sorting.MergeSort(inputArr, 0, count - 1);
					for (int i = 0; i < count; i++)
					{
						outdata << context.marshal_as<string>(Convert::ToString(inputArr[i])) << "\n";

						lstSorted->Items->Add(Convert::ToString(inputArr[i]));
					}

				}
				else if (cmbSortingType->Text == "Quick Sort")
				{
					for (int i = 0; i < count; i++)
					{
						lstUnsorted->Items->Add(Convert::ToString(inputArr[i]));
					}
					sorting.QuickSort(inputArr, 0, count - 1);
					for (int i = 0; i < count; i++)
					{
						outdata << context.marshal_as<string>(Convert::ToString(inputArr[i])) << "\n";

						lstSorted->Items->Add(Convert::ToString(inputArr[i]));
					}

				}
				else if (cmbSortingType->Text == "Heap Sort")
				{
					for (int i = 0; i < count; i++)
					{
						lstUnsorted->Items->Add(Convert::ToString(inputArr[i]));
					}
					sorting.heapSort(inputArr, count);
					for (int i = 0; i < count; i++)
					{
						outdata << context.marshal_as<string>(Convert::ToString(inputArr[i])) << "\n";

						lstSorted->Items->Add(Convert::ToString(inputArr[i]));
					}

				}
				else if (cmbSortingType->Text == "Count Sort")
				{
					for (int i = 0; i < count; i++)
					{
						lstUnsorted->Items->Add(Convert::ToString(inputArr[i]));
					}
					sorting.CountSort(inputArr, count);
					for (int i = 0; i < count; i++)
					{
						outdata << context.marshal_as<string>(Convert::ToString(inputArr[i])) << "\n";

						lstSorted->Items->Add(Convert::ToString(inputArr[i]));
					}

				}
				else if (cmbSortingType->Text == "Radix Sort")
				{
					for (int i = 0; i < count; i++)
					{
						lstUnsorted->Items->Add(Convert::ToString(inputArr[i]));
					}
					sorting.radixSort(inputArr, count);
					for (int i = 0; i < count; i++)
					{
						outdata << context.marshal_as<string>(Convert::ToString(inputArr[i])) << "\n";

						lstSorted->Items->Add(Convert::ToString(inputArr[i]));
					}

				}
				else if (cmbSortingType->Text == "Bucket Sort")
				{
					for (int i = 0; i < count; i++)
					{
						lstUnsorted->Items->Add(Convert::ToString(inputArr[i]));
					}
					sorting.bucketSort(inputArr, count);
					for (int i = 0; i < count; i++)
					{
						outdata << context.marshal_as<string>(Convert::ToString(inputArr[i])) << "\n";

						lstSorted->Items->Add(Convert::ToString(inputArr[i]));
					}

				}

				MessageBox::Show(fileDirectory + "\\" + "sorted.txt");
			}

		}
		catch (Exception ^ex){
			MessageBox::Show(ex->Message);

		}
		catch (...){
			MessageBox::Show("An error occurred");
		}


	}
	private: System::Void cmbSortingType_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (e->KeyChar == (Char)Keys::Enter){
			MessageBox::Show("key pressed");
			btnGetResult_Click(sender, e);
		}
	}

	};
}
