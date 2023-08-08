#pragma once

namespace WordCounterApp {

    using namespace System;

    public ref class WordCounterForm : public System::Windows::Forms::Form {
    public:
        WordCounterForm(void) {
            InitializeComponent();
        }

    protected:
        ~WordCounterForm() {
            if (components) {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ titleLabel;
        System::Windows::Forms::TextBox^ inputTextBox;
        System::Windows::Forms::Button^ countButton;
        System::Windows::Forms::Label^ resultLabel;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            this->titleLabel = (gcnew System::Windows::Forms::Label());
            this->inputTextBox = (gcnew System::Windows::Forms::TextBox());
            this->countButton = (gcnew System::Windows::Forms::Button());
            this->resultLabel = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // titleLabel
            // 
            this->titleLabel->AutoSize = true;
            this->titleLabel->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->titleLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->titleLabel->Location = System::Drawing::Point(189, 33);
            this->titleLabel->Name = L"titleLabel";
            this->titleLabel->Size = System::Drawing::Size(378, 54);
            this->titleLabel->TabIndex = 0;
            this->titleLabel->Text = L"Word Counter Tool";
            // 
            // inputTextBox
            // 
            this->inputTextBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
            this->inputTextBox->Location = System::Drawing::Point(57, 103);
            this->inputTextBox->Multiline = true;
            this->inputTextBox->Name = L"inputTextBox";
            this->inputTextBox->Size = System::Drawing::Size(631, 136);
            this->inputTextBox->TabIndex = 1;
            // 
            // countButton
            // 
            this->countButton->BackColor = System::Drawing::Color::DarkBlue;
            this->countButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->countButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->countButton->ForeColor = System::Drawing::Color::White;
            this->countButton->Location = System::Drawing::Point(198, 255);
            this->countButton->Name = L"countButton";
            this->countButton->Size = System::Drawing::Size(369, 40);
            this->countButton->TabIndex = 2;
            this->countButton->Text = L"Count Words";
            this->countButton->UseVisualStyleBackColor = false;
            this->countButton->Click += gcnew System::EventHandler(this, &WordCounterForm::countButton_Click);
            // 
            // resultLabel
            // 
            this->resultLabel->AutoSize = true;
            this->resultLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->resultLabel->Location = System::Drawing::Point(203, 366);
            this->resultLabel->Name = L"resultLabel";
            this->resultLabel->Size = System::Drawing::Size(0, 32);
            this->resultLabel->TabIndex = 3;
            // 
            // WordCounterForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(750, 500);
            this->Controls->Add(this->resultLabel);
            this->Controls->Add(this->countButton);
            this->Controls->Add(this->inputTextBox);
            this->Controls->Add(this->titleLabel);
            this->Name = L"WordCounterForm";
            this->Text = L"Word Count Calculator";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void countButton_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ inputText = inputTextBox->Text;
        int wordCount = CountWords(inputText);
        resultLabel->Text = "Word Count: " + wordCount;
    }

    private: int CountWords(String^ input) {
        array<Char>^ delimiters = { ' ', '\t', '\n' };
        int wordCount = 0;
        int length = input->Length;

        for (int i = 0; i < length; i++) {
            if (Array::IndexOf(delimiters, input[i]) != -1) {
                if (i > 0 && Array::IndexOf(delimiters, input[i - 1]) == -1) {
                    wordCount++;
                }
            }
        }

        if (length > 0 && Array::IndexOf(delimiters, input[length - 1]) == -1) {
            wordCount++;
        }

        return wordCount;
    }
    };
}
