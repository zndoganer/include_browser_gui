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
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

	private: System::Windows::Forms::Button^ button_browse;
	private: System::Windows::Forms::Button^ button_OK;

	private: System::Windows::Forms::Label^ label_info;
	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;



	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ textBox_project_path;


	private:

		System::String^ selectedDir;
	private: System::Windows::Forms::TreeView^ treeView;

		   Hashtable hashtable;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ creditsToolStripMenuItem;
	private: System::Windows::Forms::Label^ label_info_orange;

	private: System::Windows::Forms::Label^ label_info_red;





		   bool treeViewDisplay_b;

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
			   this->components = (gcnew System::ComponentModel::Container());
			   this->button_browse = (gcnew System::Windows::Forms::Button());
			   this->button_OK = (gcnew System::Windows::Forms::Button());
			   this->label_info = (gcnew System::Windows::Forms::Label());
			   this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->textBox_project_path = (gcnew System::Windows::Forms::Label());
			   this->treeView = (gcnew System::Windows::Forms::TreeView());
			   this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->openFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->creditsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->label_info_orange = (gcnew System::Windows::Forms::Label());
			   this->label_info_red = (gcnew System::Windows::Forms::Label());
			   this->menuStrip1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // button_browse
			   // 
			   this->button_browse->BackColor = System::Drawing::Color::Green;
			   this->button_browse->FlatAppearance->BorderSize = 0;
			   this->button_browse->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button_browse->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->button_browse->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->button_browse->Location = System::Drawing::Point(18, 79);
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
			   this->button_OK->BackColor = System::Drawing::Color::Green;
			   this->button_OK->FlatAppearance->BorderColor = System::Drawing::Color::Blue;
			   this->button_OK->FlatAppearance->BorderSize = 0;
			   this->button_OK->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button_OK->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->button_OK->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->button_OK->Location = System::Drawing::Point(121, 79);
			   this->button_OK->Margin = System::Windows::Forms::Padding(2);
			   this->button_OK->Name = L"button_OK";
			   this->button_OK->Size = System::Drawing::Size(95, 32);
			   this->button_OK->TabIndex = 1;
			   this->button_OK->Text = L"OK";
			   this->button_OK->UseVisualStyleBackColor = false;
			   this->button_OK->Click += gcnew System::EventHandler(this, &include_browser::map_includes_Click);
			   // 
			   // label_info
			   // 
			   this->label_info->AutoSize = true;
			   this->label_info->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				   static_cast<System::Int32>(static_cast<System::Byte>(64)));
			   this->label_info->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->label_info->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->label_info->Location = System::Drawing::Point(236, 85);
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
			   this->panel1->Location = System::Drawing::Point(17, 59);
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
			   this->textBox_project_path->Location = System::Drawing::Point(15, 44);
			   this->textBox_project_path->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->textBox_project_path->Name = L"textBox_project_path";
			   this->textBox_project_path->Size = System::Drawing::Size(0, 13);
			   this->textBox_project_path->TabIndex = 6;
			   // 
			   // treeView
			   // 
			   this->treeView->BackColor = System::Drawing::Color::Black;
			   this->treeView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->treeView->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->treeView->ForeColor = System::Drawing::SystemColors::HighlightText;
			   this->treeView->Location = System::Drawing::Point(17, 130);
			   this->treeView->Name = L"treeView";
			   this->treeView->Size = System::Drawing::Size(484, 300);
			   this->treeView->TabIndex = 8;
			   this->toolTip1->SetToolTip(this->treeView, L"Double Click Expand/Collapse All");
			   this->treeView->Visible = false;
			   this->treeView->DoubleClick += gcnew System::EventHandler(this, &include_browser::treeView_DoubleClick);
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				   this->fileToolStripMenuItem,
					   this->aboutToolStripMenuItem
			   });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(534, 24);
			   this->menuStrip1->TabIndex = 9;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // fileToolStripMenuItem
			   // 
			   this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->openFileToolStripMenuItem });
			   this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			   this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			   this->fileToolStripMenuItem->Text = L"File";
			   // 
			   // openFileToolStripMenuItem
			   // 
			   this->openFileToolStripMenuItem->Name = L"openFileToolStripMenuItem";
			   this->openFileToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			   this->openFileToolStripMenuItem->Text = L"Open File";
			   this->openFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &include_browser::menu_file_click);
			   // 
			   // aboutToolStripMenuItem
			   // 
			   this->aboutToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->creditsToolStripMenuItem });
			   this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			   this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			   this->aboutToolStripMenuItem->Text = L"About";
			   // 
			   // creditsToolStripMenuItem
			   // 
			   this->creditsToolStripMenuItem->Name = L"creditsToolStripMenuItem";
			   this->creditsToolStripMenuItem->Size = System::Drawing::Size(111, 22);
			   this->creditsToolStripMenuItem->Text = L"Credits";
			   this->creditsToolStripMenuItem->Click += gcnew System::EventHandler(this, &include_browser::menu_about_click);
			   // 
			   // label_info_orange
			   // 
			   this->label_info_orange->AutoSize = true;
			   this->label_info_orange->BackColor = System::Drawing::Color::Black;
			   this->label_info_orange->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			   this->label_info_orange->ForeColor = System::Drawing::Color::Orange;
			   this->label_info_orange->Location = System::Drawing::Point(16, 446);
			   this->label_info_orange->Name = L"label_info_orange";
			   this->label_info_orange->Size = System::Drawing::Size(159, 17);
			   this->label_info_orange->TabIndex = 10;
			   this->label_info_orange->Text = L"Indirect Mutual Inclusion";
			   this->label_info_orange->Visible = false;
			   // 
			   // label_info_red
			   // 
			   this->label_info_red->AutoSize = true;
			   this->label_info_red->BackColor = System::Drawing::Color::Black;
			   this->label_info_red->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			   this->label_info_red->ForeColor = System::Drawing::Color::Red;
			   this->label_info_red->Location = System::Drawing::Point(184, 446);
			   this->label_info_red->Name = L"label_info_red";
			   this->label_info_red->Size = System::Drawing::Size(150, 17);
			   this->label_info_red->TabIndex = 11;
			   this->label_info_red->Text = L"Direct Mutual Inclusion";
			   this->label_info_red->Visible = false;
			   // 
			   // include_browser
			   // 
			   this->AllowDrop = true;
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->AutoScroll = true;
			   this->AutoSize = true;
			   this->BackColor = System::Drawing::Color::Black;
			   this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->ClientSize = System::Drawing::Size(534, 476);
			   this->Controls->Add(this->label_info_red);
			   this->Controls->Add(this->label_info_orange);
			   this->Controls->Add(this->treeView);
			   this->Controls->Add(this->textBox_project_path);
			   this->Controls->Add(this->panel1);
			   this->Controls->Add(this->label_info);
			   this->Controls->Add(this->button_OK);
			   this->Controls->Add(this->button_browse);
			   this->Controls->Add(this->menuStrip1);
			   this->MainMenuStrip = this->menuStrip1;
			   this->Name = L"include_browser";
			   this->Text = L"Include Browser for C/C++ Written Projects";
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
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
		treeView->Visible = true;
		treeView->Nodes->Clear();
		// Clear hashtable for new attempts.
		hashtable.Clear();
		// Hide labels if inclusions have not found yet.
		label_info_red->Visible = false;
		label_info_orange->Visible = false;

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
			treeView->Nodes->Add(key);

			for (int valueIndex = 0; valueIndex < values->Count; valueIndex++)
			{
				System::String^ value = values[valueIndex];
				// add sub-nodes
				treeView->Nodes[keyIndex]->Nodes->Add(value);
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
					treeView->Nodes[keyIndex]->BackColor = BackColor.Orange;
				}
				else
				{
					treeView->Nodes[keyIndex]->BackColor = BackColor.Red;
				}

				label_info->BackColor = BackColor.Red;
				label_info->Text = "Mutual inclusion is found.";
				// Hide labels if inclusions have not found yet.
				label_info_red->Visible = true;
				label_info_orange->Visible = true;
			}
		}

		if (false == mutual_inclusion_is_found_flag)
			label_info->Text = "Mutual inclusion is not found.";

		treeView->Sort();
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

	/* Double Clicks Expand All TreeView or Collapse All */
	private: System::Void treeView_DoubleClick(System::Object^ sender, System::EventArgs^ e) 
	{
		treeViewDisplay_b = !treeViewDisplay_b;
		
		if(treeViewDisplay_b)
		    treeView->ExpandAll();
		else
			treeView->CollapseAll();
	}

	private: System::Void menu_file_click(System::Object^ sender, System::EventArgs^ e) 
	{
		browse_button_Click(nullptr,nullptr);

		map_includes_Click(nullptr, nullptr);
	}

	private: System::Void menu_about_click(System::Object^ sender, System::EventArgs^ e) 
	{		
		MessageBox::Show( "Nothing special here... \n\n v0.0.2 / 02.03.2024", "About");
	}

};
}
