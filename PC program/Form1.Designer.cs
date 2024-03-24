
using System;
using System.Linq;

namespace PIC_MAXI_WEB_controller
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;
        string receivedData = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            DisplayPanel = new System.Windows.Forms.GroupBox();
            TextBox = new System.Windows.Forms.TextBox();
            SendBttn = new System.Windows.Forms.Button();
            LEDGroupBox = new System.Windows.Forms.GroupBox();
            LED1Button = new System.Windows.Forms.Button();
            LED2Button = new System.Windows.Forms.Button();
            LED3Button = new System.Windows.Forms.Button();
            ADCGroupBox = new System.Windows.Forms.GroupBox();
            PotValue = new System.Windows.Forms.Label();
            Temp = new System.Windows.Forms.Label();
            ButtonsGroupBox = new System.Windows.Forms.GroupBox();
            Button2Label = new System.Windows.Forms.Label();
            Button1Label = new System.Windows.Forms.Label();
            folderBrowserDialog1 = new System.Windows.Forms.FolderBrowserDialog();
            COMDropDown = new System.Windows.Forms.ComboBox();
            SelectPortLabel = new System.Windows.Forms.Label();
            getInfoTimer = new System.Windows.Forms.Timer(components);
            DisplayPanel.SuspendLayout();
            LEDGroupBox.SuspendLayout();
            ADCGroupBox.SuspendLayout();
            ButtonsGroupBox.SuspendLayout();
            SuspendLayout();
            // 
            // DisplayPanel
            // 
            DisplayPanel.BackColor = System.Drawing.SystemColors.ButtonFace;
            DisplayPanel.Controls.Add(TextBox);
            DisplayPanel.Controls.Add(SendBttn);
            DisplayPanel.Enabled = false;
            DisplayPanel.Location = new System.Drawing.Point(12, 46);
            DisplayPanel.Name = "DisplayPanel";
            DisplayPanel.Size = new System.Drawing.Size(208, 146);
            DisplayPanel.TabIndex = 2;
            DisplayPanel.TabStop = false;
            DisplayPanel.Text = "LCD";
            // 
            // TextBox
            // 
            TextBox.Font = new System.Drawing.Font("Segoe UI", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            TextBox.Location = new System.Drawing.Point(6, 26);
            TextBox.MaxLength = 32;
            TextBox.Multiline = true;
            TextBox.Name = "TextBox";
            TextBox.Size = new System.Drawing.Size(196, 76);
            TextBox.TabIndex = 0;
            TextBox.KeyDown += TextBox_KeyDown;
            // 
            // SendBttn
            // 
            SendBttn.Location = new System.Drawing.Point(104, 108);
            SendBttn.Name = "SendBttn";
            SendBttn.Size = new System.Drawing.Size(98, 29);
            SendBttn.TabIndex = 1;
            SendBttn.Text = "Send";
            SendBttn.UseVisualStyleBackColor = true;
            SendBttn.Click += SendBttn_Click;
            // 
            // LEDGroupBox
            // 
            LEDGroupBox.Controls.Add(LED1Button);
            LEDGroupBox.Controls.Add(LED2Button);
            LEDGroupBox.Controls.Add(LED3Button);
            LEDGroupBox.Enabled = false;
            LEDGroupBox.Location = new System.Drawing.Point(12, 198);
            LEDGroupBox.Name = "LEDGroupBox";
            LEDGroupBox.Size = new System.Drawing.Size(61, 151);
            LEDGroupBox.TabIndex = 4;
            LEDGroupBox.TabStop = false;
            LEDGroupBox.Text = "LEDs";
            // 
            // LED1Button
            // 
            LED1Button.Location = new System.Drawing.Point(16, 30);
            LED1Button.Name = "LED1Button";
            LED1Button.Size = new System.Drawing.Size(29, 29);
            LED1Button.TabIndex = 8;
            LED1Button.UseVisualStyleBackColor = true;
            LED1Button.Click += LED1Button_Click;
            // 
            // LED2Button
            // 
            LED2Button.Location = new System.Drawing.Point(16, 100);
            LED2Button.Name = "LED2Button";
            LED2Button.Size = new System.Drawing.Size(29, 29);
            LED2Button.TabIndex = 6;
            LED2Button.UseVisualStyleBackColor = true;
            LED2Button.Click += LED3Button_Click;
            // 
            // LED3Button
            // 
            LED3Button.Location = new System.Drawing.Point(16, 65);
            LED3Button.Name = "LED3Button";
            LED3Button.Size = new System.Drawing.Size(29, 29);
            LED3Button.TabIndex = 7;
            LED3Button.UseVisualStyleBackColor = true;
            LED3Button.Click += LED2Button_Click;
            // 
            // ADCGroupBox
            // 
            ADCGroupBox.Controls.Add(PotValue);
            ADCGroupBox.Controls.Add(Temp);
            ADCGroupBox.Enabled = false;
            ADCGroupBox.Location = new System.Drawing.Point(79, 198);
            ADCGroupBox.Name = "ADCGroupBox";
            ADCGroupBox.Size = new System.Drawing.Size(141, 72);
            ADCGroupBox.TabIndex = 6;
            ADCGroupBox.TabStop = false;
            ADCGroupBox.Text = "Analog values";
            // 
            // PotValue
            // 
            PotValue.AutoSize = true;
            PotValue.Location = new System.Drawing.Point(6, 43);
            PotValue.Name = "PotValue";
            PotValue.Size = new System.Drawing.Size(75, 20);
            PotValue.TabIndex = 8;
            PotValue.Text = "Pot. value:";
            // 
            // Temp
            // 
            Temp.AutoSize = true;
            Temp.Location = new System.Drawing.Point(6, 23);
            Temp.Name = "Temp";
            Temp.Size = new System.Drawing.Size(96, 20);
            Temp.TabIndex = 7;
            Temp.Text = "Temperature:";
            // 
            // ButtonsGroupBox
            // 
            ButtonsGroupBox.Controls.Add(Button2Label);
            ButtonsGroupBox.Controls.Add(Button1Label);
            ButtonsGroupBox.Enabled = false;
            ButtonsGroupBox.Location = new System.Drawing.Point(79, 276);
            ButtonsGroupBox.Name = "ButtonsGroupBox";
            ButtonsGroupBox.Size = new System.Drawing.Size(141, 73);
            ButtonsGroupBox.TabIndex = 5;
            ButtonsGroupBox.TabStop = false;
            ButtonsGroupBox.Text = "Button states";
            // 
            // Button2Label
            // 
            Button2Label.AutoSize = true;
            Button2Label.Location = new System.Drawing.Point(6, 43);
            Button2Label.Name = "Button2Label";
            Button2Label.Size = new System.Drawing.Size(68, 20);
            Button2Label.TabIndex = 10;
            Button2Label.Text = "Button 2:";
            // 
            // Button1Label
            // 
            Button1Label.AutoSize = true;
            Button1Label.Location = new System.Drawing.Point(6, 23);
            Button1Label.Name = "Button1Label";
            Button1Label.Size = new System.Drawing.Size(68, 20);
            Button1Label.TabIndex = 9;
            Button1Label.Text = "Button 1:";
            // 
            // COMDropDown
            // 
            COMDropDown.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            COMDropDown.FormattingEnabled = true;
            COMDropDown.Location = new System.Drawing.Point(116, 12);
            COMDropDown.MaxDropDownItems = 16;
            COMDropDown.Name = "COMDropDown";
            COMDropDown.Size = new System.Drawing.Size(104, 28);
            COMDropDown.Sorted = true;
            COMDropDown.TabIndex = 7;
            COMDropDown.SelectedIndexChanged += COMPortSelected;
            // 
            // SelectPortLabel
            // 
            SelectPortLabel.AutoSize = true;
            SelectPortLabel.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            SelectPortLabel.Location = new System.Drawing.Point(15, 14);
            SelectPortLabel.Name = "SelectPortLabel";
            SelectPortLabel.Size = new System.Drawing.Size(64, 23);
            SelectPortLabel.TabIndex = 8;
            SelectPortLabel.Text = "Device:";
            // 
            // getInfoTimer
            // 
            getInfoTimer.Tick += TickPassed;
            // 
            // Form1
            // 
            AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            ClientSize = new System.Drawing.Size(232, 365);
            Controls.Add(SelectPortLabel);
            Controls.Add(COMDropDown);
            Controls.Add(ADCGroupBox);
            Controls.Add(ButtonsGroupBox);
            Controls.Add(LEDGroupBox);
            Controls.Add(DisplayPanel);
            MaximizeBox = false;
            MinimizeBox = false;
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load;
            DisplayPanel.ResumeLayout(false);
            DisplayPanel.PerformLayout();
            LEDGroupBox.ResumeLayout(false);
            ADCGroupBox.ResumeLayout(false);
            ADCGroupBox.PerformLayout();
            ButtonsGroupBox.ResumeLayout(false);
            ButtonsGroupBox.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private System.Windows.Forms.FolderBrowserDialog folderBrowserDialog1;
        private System.Windows.Forms.TextBox TextBox;
        private System.Windows.Forms.Button SendBttn;
        private System.Windows.Forms.GroupBox DisplayPanel;
        private System.Windows.Forms.GroupBox LEDGroupBox;
        private System.Windows.Forms.Button LED3Button;
        private System.Windows.Forms.Button LED2Button;
        private System.Windows.Forms.Button LED1Button;
        private System.Windows.Forms.GroupBox ButtonsGroupBox;
        private System.Windows.Forms.GroupBox ADCGroupBox;
        private System.Windows.Forms.Label PotValue;
        private System.Windows.Forms.Label Temp;
        private System.Windows.Forms.Label Button2Label;
        private System.Windows.Forms.Label Button1Label;
        private System.Windows.Forms.ComboBox COMDropDown;
        private System.Windows.Forms.Label SelectPortLabel;
        public void SetLabels(string[] values)
        {
            if (InvokeRequired)
            {
                try { Invoke(new Action(() => SetLabels(values))); }
                catch (ObjectDisposedException) { }
                return;
            }
            this.Button1Label.Text = $"Button 1: {(values[0][0] == (char)1 ? "Released" : "Pressed")}";
            this.Button2Label.Text = $"Button 2: {(values[1][0] == (char)1 ? "Released" : "Pressed")}";
            this.PotValue.Text = $"Pot. value: {values[2]}";
            this.Temp.Text = $"Temperature: {values[3]}°C";
        }

        private System.Windows.Forms.Timer getInfoTimer;
    }
}

