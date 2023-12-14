
using System;

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
            this.DisplayPanel = new System.Windows.Forms.GroupBox();
            this.TextBox = new System.Windows.Forms.TextBox();
            this.SendBttn = new System.Windows.Forms.Button();
            this.LEDGroupBox = new System.Windows.Forms.GroupBox();
            this.LED1Button = new System.Windows.Forms.Button();
            this.LED2Button = new System.Windows.Forms.Button();
            this.LED3Button = new System.Windows.Forms.Button();
            this.ADCGroupBox = new System.Windows.Forms.GroupBox();
            this.PotValue = new System.Windows.Forms.Label();
            this.Temp = new System.Windows.Forms.Label();
            this.ButtonsGroupBox = new System.Windows.Forms.GroupBox();
            this.Button2Label = new System.Windows.Forms.Label();
            this.Button1Label = new System.Windows.Forms.Label();
            this.folderBrowserDialog1 = new System.Windows.Forms.FolderBrowserDialog();
            this.COMDropDown = new System.Windows.Forms.ComboBox();
            this.SelectPortLabel = new System.Windows.Forms.Label();
            this.DisplayPanel.SuspendLayout();
            this.LEDGroupBox.SuspendLayout();
            this.ADCGroupBox.SuspendLayout();
            this.ButtonsGroupBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // DisplayPanel
            // 
            this.DisplayPanel.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.DisplayPanel.Controls.Add(this.TextBox);
            this.DisplayPanel.Controls.Add(this.SendBttn);
            this.DisplayPanel.Enabled = false;
            this.DisplayPanel.Location = new System.Drawing.Point(12, 46);
            this.DisplayPanel.Name = "DisplayPanel";
            this.DisplayPanel.Size = new System.Drawing.Size(208, 146);
            this.DisplayPanel.TabIndex = 2;
            this.DisplayPanel.TabStop = false;
            this.DisplayPanel.Text = "LCD";
            // 
            // TextBox
            // 
            this.TextBox.Font = new System.Drawing.Font("Segoe UI", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.TextBox.Location = new System.Drawing.Point(6, 26);
            this.TextBox.MaxLength = 32;
            this.TextBox.Multiline = true;
            this.TextBox.Name = "TextBox";
            this.TextBox.Size = new System.Drawing.Size(196, 76);
            this.TextBox.TabIndex = 0;
            // 
            // SendBttn
            // 
            this.SendBttn.Location = new System.Drawing.Point(104, 108);
            this.SendBttn.Name = "SendBttn";
            this.SendBttn.Size = new System.Drawing.Size(98, 29);
            this.SendBttn.TabIndex = 1;
            this.SendBttn.Text = "Send";
            this.SendBttn.UseVisualStyleBackColor = true;
            this.SendBttn.Click += new System.EventHandler(this.SendBttn_Click);
            // 
            // LEDGroupBox
            // 
            this.LEDGroupBox.Controls.Add(this.LED1Button);
            this.LEDGroupBox.Controls.Add(this.LED2Button);
            this.LEDGroupBox.Controls.Add(this.LED3Button);
            this.LEDGroupBox.Enabled = false;
            this.LEDGroupBox.Location = new System.Drawing.Point(12, 198);
            this.LEDGroupBox.Name = "LEDGroupBox";
            this.LEDGroupBox.Size = new System.Drawing.Size(61, 151);
            this.LEDGroupBox.TabIndex = 4;
            this.LEDGroupBox.TabStop = false;
            this.LEDGroupBox.Text = "LEDs";
            // 
            // LED1Button
            // 
            this.LED1Button.Location = new System.Drawing.Point(16, 30);
            this.LED1Button.Name = "LED1Button";
            this.LED1Button.Size = new System.Drawing.Size(29, 29);
            this.LED1Button.TabIndex = 8;
            this.LED1Button.UseVisualStyleBackColor = true;
            this.LED1Button.Click += new System.EventHandler(this.LED1Button_Click);
            // 
            // LED2Button
            // 
            this.LED2Button.Location = new System.Drawing.Point(16, 100);
            this.LED2Button.Name = "LED2Button";
            this.LED2Button.Size = new System.Drawing.Size(29, 29);
            this.LED2Button.TabIndex = 6;
            this.LED2Button.UseVisualStyleBackColor = true;
            this.LED2Button.Click += new System.EventHandler(this.LED3Button_Click);
            // 
            // LED3Button
            // 
            this.LED3Button.Location = new System.Drawing.Point(16, 65);
            this.LED3Button.Name = "LED3Button";
            this.LED3Button.Size = new System.Drawing.Size(29, 29);
            this.LED3Button.TabIndex = 7;
            this.LED3Button.UseVisualStyleBackColor = true;
            this.LED3Button.Click += new System.EventHandler(this.LED2Button_Click);
            // 
            // ADCGroupBox
            // 
            this.ADCGroupBox.Controls.Add(this.PotValue);
            this.ADCGroupBox.Controls.Add(this.Temp);
            this.ADCGroupBox.Enabled = false;
            this.ADCGroupBox.Location = new System.Drawing.Point(79, 198);
            this.ADCGroupBox.Name = "ADCGroupBox";
            this.ADCGroupBox.Size = new System.Drawing.Size(141, 72);
            this.ADCGroupBox.TabIndex = 6;
            this.ADCGroupBox.TabStop = false;
            this.ADCGroupBox.Text = "Analog values";
            // 
            // PotValue
            // 
            this.PotValue.AutoSize = true;
            this.PotValue.Location = new System.Drawing.Point(6, 43);
            this.PotValue.Name = "PotValue";
            this.PotValue.Size = new System.Drawing.Size(75, 20);
            this.PotValue.TabIndex = 8;
            this.PotValue.Text = "Pot. value:";
            // 
            // Temp
            // 
            this.Temp.AutoSize = true;
            this.Temp.Location = new System.Drawing.Point(6, 23);
            this.Temp.Name = "Temp";
            this.Temp.Size = new System.Drawing.Size(49, 20);
            this.Temp.TabIndex = 7;
            this.Temp.Text = "Temp:";
            // 
            // ButtonsGroupBox
            // 
            this.ButtonsGroupBox.Controls.Add(this.Button2Label);
            this.ButtonsGroupBox.Controls.Add(this.Button1Label);
            this.ButtonsGroupBox.Enabled = false;
            this.ButtonsGroupBox.Location = new System.Drawing.Point(79, 276);
            this.ButtonsGroupBox.Name = "ButtonsGroupBox";
            this.ButtonsGroupBox.Size = new System.Drawing.Size(141, 73);
            this.ButtonsGroupBox.TabIndex = 5;
            this.ButtonsGroupBox.TabStop = false;
            this.ButtonsGroupBox.Text = "Button states";
            // 
            // Button2Label
            // 
            this.Button2Label.AutoSize = true;
            this.Button2Label.Location = new System.Drawing.Point(6, 43);
            this.Button2Label.Name = "Button2Label";
            this.Button2Label.Size = new System.Drawing.Size(68, 20);
            this.Button2Label.TabIndex = 10;
            this.Button2Label.Text = "Button 2:";
            // 
            // Button1Label
            // 
            this.Button1Label.AutoSize = true;
            this.Button1Label.Location = new System.Drawing.Point(6, 23);
            this.Button1Label.Name = "Button1Label";
            this.Button1Label.Size = new System.Drawing.Size(68, 20);
            this.Button1Label.TabIndex = 9;
            this.Button1Label.Text = "Button 1:";
            // 
            // COMDropDown
            // 
            this.COMDropDown.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.COMDropDown.FormattingEnabled = true;
            this.COMDropDown.Location = new System.Drawing.Point(116, 12);
            this.COMDropDown.MaxDropDownItems = 16;
            this.COMDropDown.Name = "COMDropDown";
            this.COMDropDown.Size = new System.Drawing.Size(104, 28);
            this.COMDropDown.Sorted = true;
            this.COMDropDown.TabIndex = 7;
            this.COMDropDown.SelectedIndexChanged += new System.EventHandler(this.COMPortSelected);
            // 
            // SelectPortLabel
            // 
            this.SelectPortLabel.AutoSize = true;
            this.SelectPortLabel.Font = new System.Drawing.Font("Segoe UI", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.SelectPortLabel.Location = new System.Drawing.Point(15, 14);
            this.SelectPortLabel.Name = "SelectPortLabel";
            this.SelectPortLabel.Size = new System.Drawing.Size(92, 23);
            this.SelectPortLabel.TabIndex = 8;
            this.SelectPortLabel.Text = "Serial port:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(232, 365);
            this.Controls.Add(this.SelectPortLabel);
            this.Controls.Add(this.COMDropDown);
            this.Controls.Add(this.ADCGroupBox);
            this.Controls.Add(this.ButtonsGroupBox);
            this.Controls.Add(this.LEDGroupBox);
            this.Controls.Add(this.DisplayPanel);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.DisplayPanel.ResumeLayout(false);
            this.DisplayPanel.PerformLayout();
            this.LEDGroupBox.ResumeLayout(false);
            this.ADCGroupBox.ResumeLayout(false);
            this.ADCGroupBox.PerformLayout();
            this.ButtonsGroupBox.ResumeLayout(false);
            this.ButtonsGroupBox.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

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
            values[0] = values[0] == "1" ? "Released" : "Pressed";
            values[1] = values[1] == "1" ? "Released" : "Pressed";
            this.Button1Label.Text = "Button 1: " + values[1];
            this.Button2Label.Text = "Button 2: " + values[0];
            this.PotValue.Text = "Pot. value: " + int.Parse(values[2]);
        }
    }
}

