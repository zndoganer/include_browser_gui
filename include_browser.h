#pragma once

#include <string>
#include <iostream>
#include <msclr/marshal_cppstd.h>
#include <stdexcept>

namespace include_browser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Resources;
	using namespace System::IO;

	/// <summary>
	/// Summary for browser
	/// </summary>
	public ref class include_browser : public System::Windows::Forms::Form
	{
	public:
		include_browser(void)
		{
			InitializeComponent();

			this->Icon = gcnew System::Drawing::Icon("andromeda-chain_38477.ico");
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~include_browser()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::Button^ button_browse;
	private: System::Windows::Forms::Button^ button_OK;
	private: System::Windows::Forms::DataGridView^ result_table;
	private: System::Windows::Forms::Label^ label_info;
	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;



	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ textBox_project_path;
	private: System::Windows::Forms::CheckBox^ chBox_show_mutuals;

	private:

		System::String^ selectedDir;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ header_file;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ included_files;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ mutual_inclusion_stat;





		   Hashtable hashtable;

		   ref class is_cyclic_result
		   {
		   public:
			   bool is_cyclic_u;
			   System::String^ file;

			   void set_values(is_cyclic_result^ is_cyclic_result_st)
			   {
				   this->is_cyclic_u = is_cyclic_result_st->is_cyclic_u;
				   this->file = is_cyclic_result_st->file;
			   }
		   };



#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->button_browse = (gcnew System::Windows::Forms::Button());
			   this->button_OK = (gcnew System::Windows::Forms::Button());
			   this->result_table = (gcnew System::Windows::Forms::DataGridView());
			   this->header_file = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->included_files = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->mutual_inclusion_stat = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->label_info = (gcnew System::Windows::Forms::Label());
			   this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->textBox_project_path = (gcnew System::Windows::Forms::Label());
			   this->chBox_show_mutuals = (gcnew System::Windows::Forms::CheckBox());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->result_table))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // button_browse
			   // 
			   this->button_browse->BackColor = System::Drawing::Color::Black;
			   this->button_browse->FlatAppearance->BorderSize = 0;
			   this->button_browse->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button_browse->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->button_browse->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->button_browse->Location = System::Drawing::Point(20, 64);
			   this->button_browse->Margin = System::Windows::Forms::Padding(2);
			   this->button_browse->Name = L"button_browse";
			   this->button_browse->Size = System::Drawing::Size(99, 32);
			   this->button_browse->TabIndex = 0;
			   this->button_browse->Text = L"Browse";
			   this->button_browse->UseVisualStyleBackColor = false;
			   this->button_browse->Click += gcnew System::EventHandler(this, &include_browser::browse_button_Click);
			   // 
			   // button_OK
			   // 
			   this->button_OK->BackColor = System::Drawing::Color::Black;
			   this->button_OK->FlatAppearance->BorderColor = System::Drawing::Color::Blue;
			   this->button_OK->FlatAppearance->BorderSize = 0;
			   this->button_OK->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button_OK->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->button_OK->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->button_OK->Location = System::Drawing::Point(123, 64);
			   this->button_OK->Margin = System::Windows::Forms::Padding(2);
			   this->button_OK->Name = L"button_OK";
			   this->button_OK->Size = System::Drawing::Size(95, 32);
			   this->button_OK->TabIndex = 1;
			   this->button_OK->Text = L"OK";
			   this->button_OK->UseVisualStyleBackColor = false;
			   this->button_OK->Click += gcnew System::EventHandler(this, &include_browser::map_includes_Click);
			   // 
			   // result_table
			   // 
			   this->result_table->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			   this->result_table->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllHeaders;
			   this->result_table->BackgroundColor = System::Drawing::Color::DarkOliveGreen;
			   this->result_table->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->result_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->result_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				   this->header_file,
					   this->included_files, this->mutual_inclusion_stat
			   });
			   this->result_table->Location = System::Drawing::Point(19, 115);
			   this->result_table->Margin = System::Windows::Forms::Padding(2);
			   this->result_table->Name = L"result_table";
			   this->result_table->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToDisplayedHeaders;
			   this->result_table->RowTemplate->Height = 24;
			   this->result_table->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			   this->result_table->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			   this->result_table->Size = System::Drawing::Size(484, 295);
			   this->result_table->TabIndex = 3;
			   // 
			   // header_file
			   // 
			   this->header_file->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			   this->header_file->HeaderText = L"Header File";
			   this->header_file->Name = L"header_file";
			   // 
			   // included_files
			   // 
			   this->included_files->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			   this->included_files->HeaderText = L"Included Files";
			   this->included_files->Name = L"included_files";
			   // 
			   // mutual_inclusion_stat
			   // 
			   this->mutual_inclusion_stat->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			   this->mutual_inclusion_stat->HeaderText = L"Mutual Inclusion Status";
			   this->mutual_inclusion_stat->Name = L"mutual_inclusion_stat";
			   // 
			   // label_info
			   // 
			   this->label_info->AutoSize = true;
			   this->label_info->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				   static_cast<System::Int32>(static_cast<System::Byte>(64)));
			   this->label_info->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->label_info->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->label_info->Location = System::Drawing::Point(234, 76);
			   this->label_info->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label_info->Name = L"label_info";
			   this->label_info->Size = System::Drawing::Size(246, 20);
			   this->label_info->TabIndex = 4;
			   this->label_info->Text = L"Please select folder of the project.";
			   // 
			   // panel1
			   // 
			   this->panel1->AutoSize = true;
			   this->panel1->BackColor = System::Drawing::SystemColors::Control;
			   this->panel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->panel1->ForeColor = System::Drawing::SystemColors::Control;
			   this->panel1->Location = System::Drawing::Point(19, 41);
			   this->panel1->Margin = System::Windows::Forms::Padding(2);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(484, 2);
			   this->panel1->TabIndex = 5;
			   // 
			   // textBox_project_path
			   // 
			   this->textBox_project_path->AutoSize = true;
			   this->textBox_project_path->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				   static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			   this->textBox_project_path->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			   this->textBox_project_path->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->textBox_project_path->Location = System::Drawing::Point(17, 26);
			   this->textBox_project_path->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->textBox_project_path->Name = L"textBox_project_path";
			   this->textBox_project_path->Size = System::Drawing::Size(0, 13);
			   this->textBox_project_path->TabIndex = 6;
			   // 
			   // chBox_show_mutuals
			   // 
			   this->chBox_show_mutuals->AutoSize = true;
			   this->chBox_show_mutuals->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				   static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			   this->chBox_show_mutuals->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->chBox_show_mutuals->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->chBox_show_mutuals->Location = System::Drawing::Point(236, 53);
			   this->chBox_show_mutuals->Margin = System::Windows::Forms::Padding(2);
			   this->chBox_show_mutuals->Name = L"chBox_show_mutuals";
			   this->chBox_show_mutuals->Size = System::Drawing::Size(207, 21);
			   this->chBox_show_mutuals->TabIndex = 7;
			   this->chBox_show_mutuals->Text = L"Show Only Mutual Inclusions";
			   this->chBox_show_mutuals->UseVisualStyleBackColor = false;
			   this->chBox_show_mutuals->Visible = false;
			   this->chBox_show_mutuals->CheckedChanged += gcnew System::EventHandler(this, &include_browser::hide_non_mutuals_rows);
			   // 
			   // include_browser
			   // 
			   this->AllowDrop = true;
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->AutoScroll = true;
			   this->AutoSize = true;
			   this->BackColor = System::Drawing::Color::DarkOliveGreen;
			   this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->ClientSize = System::Drawing::Size(519, 438);
			   this->Controls->Add(this->chBox_show_mutuals);
			   this->Controls->Add(this->textBox_project_path);
			   this->Controls->Add(this->panel1);
			   this->Controls->Add(this->label_info);
			   this->Controls->Add(this->button_OK);
			   this->Controls->Add(this->button_browse);
			   this->Controls->Add(this->result_table);
			   this->Name = L"include_browser";
			   this->Text = L"Include Browser for C/C++ Written Projects";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->result_table))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

		   bool IsHeaderFile(System::String^ file)
		   {
			   return file->EndsWith(".h");
		   }

	private: System::Void browse_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		FolderBrowserDialog^ Directory = gcnew FolderBrowserDialog();
		Directory->ShowDialog();
		selectedDir = Directory->SelectedPath;
		textBox_project_path->Text = selectedDir;
		textBox_project_path->ForeColor = ForeColor.White;

	}

	private: List<System::String^>^ read_included_files(System::String^ file_path_name)
	{
		List<System::String^>^ included_h_files = gcnew List<System::String^>();
		System::String^ header_sign = "#include";

		StreamReader^ reader = gcnew  StreamReader(file_path_name);
		do
		{
			System::String^ line = reader->ReadLine();

			if (line->StartsWith(header_sign))
			{
				included_h_files->Add(line);
			}

		} while (reader->Peek() != -1);

		return included_h_files;
	}

	private: List<System::String^>^ fix_included_file_name(List<System::String^>^ file_path_name)
	{
		List<System::String^>^ fixed_h_files = gcnew List<System::String^>();
		int total_h_files_list_index = file_path_name->Capacity;

		for each (System::String ^ file in file_path_name)
		{
			file = file->Replace("include", "");
			file = file->Replace("#", "");
			file = file->Replace("\"", "");
			file = file->Replace("<", "");
			file = file->Replace(">", "");

			fixed_h_files->Add(file->Trim());
		}

		return fixed_h_files;
	}

	private: System::Void map_includes_Click(System::Object^ sender, System::EventArgs^ e)
	{

		System::String^ header_sign = ".h";
		array<System::String^>^ files;
		List<System::String^>^ files_h = gcnew List<System::String^>();
		bool header_file_is_found_flag = false;

		files = Directory::GetFiles(selectedDir);

		// Clear datagridView for new attempts.
		result_table->Visible = true;
		result_table->Rows->Clear();
		// Clear hashtable for new attempts.
		hashtable.Clear();

		for each (System::String ^ file in files)
		{
			if (file->EndsWith(header_sign))
			{
				files_h->Add(Path::GetFileName(file));
				hashtable.Add(Path::GetFileName(file)->Trim(), fix_included_file_name(read_included_files(file)));
				header_file_is_found_flag = true;
			}
		}

		if (false == header_file_is_found_flag)
		{
			label_info->Text = "Select a project that contains header files.";
			label_info->BackColor = BackColor.Red;
		}
		else
		{
			detect_mutual_inclusions();
		}
	}

	private: System::Void detect_mutual_inclusions()
	{
		is_cyclic_result^ mutual_inclusion_result = gcnew is_cyclic_result;
		bool mutual_inclusion_is_found_flag = false;

		label_info->BackColor = BackColor.Green;

		array<System::String^>^ keysArray = gcnew array<System::String^>(hashtable.Keys->Count);
		hashtable.Keys->CopyTo(keysArray, 0);

		for (int keyIndex = 0; keyIndex < keysArray->Length; keyIndex++)
		{
			System::String^ key = keysArray[keyIndex];
			List<System::String^>^ values = safe_cast<List<System::String^>^>(hashtable[key]);

			for (int valueIndex = 0; valueIndex < values->Count; valueIndex++)
			{
				System::String^ value = values[valueIndex];
				// fill the table
				result_table->Rows->Add(key, value, "not found");
			}

		}

		List<System::String^>^ keysList = gcnew List<System::String^>();

		label_info->Text = "Hey, I'm working on it!";

		for (int keyIndex = 0; keyIndex < keysArray->Length; keyIndex++)
		{
			System::String^ key = keysArray[keyIndex];
			LinkedList<System::String^>^ list = gcnew LinkedList<System::String^>(keysList);

			mutual_inclusion_result->set_values(is_cyclic(list, key, key));

			if (mutual_inclusion_result->is_cyclic_u)
			{
				mutual_inclusion_is_found_flag = true;

				if (mutual_inclusion_result->file == "2nd Degree Mutual Inclusion")
				{
					result_table->Rows[keyIndex]->Cells[2]->Style->BackColor = BackColor.Yellow;
					result_table->Rows[keyIndex]->Cells[2]->Style->ForeColor = ForeColor.Black;
					result_table->Rows[keyIndex]->Cells[2]->Value = mutual_inclusion_result->file;
				}
				else
				{
					result_table->Rows[keyIndex]->Cells[2]->Style->BackColor = BackColor.Orange;
					result_table->Rows[keyIndex]->Cells[2]->Style->ForeColor = ForeColor.Black;
					result_table->Rows[keyIndex]->Cells[2]->Value = key + "<-->" + mutual_inclusion_result->file;
				}

				label_info->BackColor = BackColor.Red;
				label_info->Text = "Mutual inclusion is found.";
			}
		}

		if (false == mutual_inclusion_is_found_flag)
			label_info->Text = "Mutual inclusion is not found.";
		else
			chBox_show_mutuals->Visible = true;
	}


	private: is_cyclic_result^ is_cyclic(LinkedList<System::String^>^ list, System::String^ key, System::String^ val)
	{
		is_cyclic_result^ is_cyclic_result_t = gcnew is_cyclic_result;
		List<System::String^>^ values;

		if (hashtable.ContainsKey(val))
		{
			values = safe_cast<List<System::String^>^>(hashtable[val]);

			for (int valueIndex = 0; valueIndex < values->Count; valueIndex++)
			{
				System::String^ value = values[valueIndex];
				list->AddLast(value);
			}

			if (list->Contains(key))
			{
				is_cyclic_result_t->is_cyclic_u = true;
				is_cyclic_result_t->file = val;
			}
			else if (list->Contains(val))
			{
				is_cyclic_result_t->is_cyclic_u = true;
				is_cyclic_result_t->file = "2nd Degree Mutual Inclusion";
			}
			else
			{
				for (int valueIndex = 0; valueIndex < values->Count; valueIndex++)
				{
					System::String^ value = values[valueIndex];
					is_cyclic_result_t->set_values(is_cyclic(list, key, value));

					if (is_cyclic_result_t->is_cyclic_u)
						break;
				}
			}
		}

		return is_cyclic_result_t;

	}


	private: System::Void hide_non_mutuals_rows(System::Object^ sender, System::EventArgs^ e)
	{
		int i = 0;

		if (chBox_show_mutuals->Checked)
		{
			while (i != result_table->Rows->Count)
			{
				if (nullptr != result_table->Rows[i]->Cells[2]->Value)
				{
					if ("not found" == result_table->Rows[i]->Cells[2]->Value->ToString())
					{
						result_table->Rows->RemoveAt(i);
					}
					else
					{
						i++;
					}
				}
				else
				{
					break;
				}

				result_table->Refresh();
			}
		}
		else
		{
			map_includes_Click(nullptr, nullptr);
		}
	}
	};
}
