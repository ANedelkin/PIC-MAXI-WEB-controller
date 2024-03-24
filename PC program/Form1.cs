using System;
using System.Windows.Forms;
using FTD2XX_NET;

namespace PIC_MAXI_WEB_controller
{
    public partial class Form1 : Form
    {
        FTDI device = new FTDI();
        int pIndex;
        public Form1()
        {
            InitializeComponent();
            this.FormBorderStyle = FormBorderStyle.FixedSingle;
        }

        private void SendBttn_Click(object sender, EventArgs e)
        {
            WriteOnLCD();
        }
        private void WriteOnLCD()
        {
            uint n = 0;
            device.Write((Char)3 + TextBox.Text + "\r", TextBox.Text.Length + 2, ref n);
            TextBox.Text = "";
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            UInt32 devicesCount = 0;
            device.GetNumberOfDevices(ref devicesCount);
            FTDI.FT_DEVICE_INFO_NODE[] devices = new FTDI.FT_DEVICE_INFO_NODE[devicesCount];
            device.GetDeviceList(devices);
            for (UInt32 i = 0; i < devicesCount; i++)
            {
                COMDropDown.Items.Add($"Device {i + 1}");
            }
            pIndex = COMDropDown.SelectedIndex;
        }
        private void COMPortSelected(object sender, EventArgs e)
        {
            if (COMDropDown.SelectedIndex != pIndex)
            {
                device.OpenByIndex((uint)COMDropDown.SelectedIndex);
                device.SetBaudRate(115200);
                device.SetDataCharacteristics(FTDI.FT_DATA_BITS.FT_BITS_8, FTDI.FT_STOP_BITS.FT_STOP_BITS_1, FTDI.FT_PARITY.FT_PARITY_NONE);
                device.SetFlowControl(FTDI.FT_FLOW_CONTROL.FT_FLOW_NONE, 0x11, 0x13);
                device.SetTimeouts(5000, 0);
                GetStatus();                
                getInfoTimer.Enabled = true;
                getInfoTimer.Start();
                pIndex = COMDropDown.SelectedIndex;
                DisplayPanel.Enabled = true;
                ADCGroupBox.Enabled = true;
                LEDGroupBox.Enabled = true;
                ButtonsGroupBox.Enabled = true;
            }
        }

        private void LED1Button_Click(object sender, EventArgs e)
        {
            uint n = 0;
            device.Write((Char)2 + "1" + "\r", 3, ref n);
        }
        private void LED2Button_Click(object sender, EventArgs e)
        {
            uint n = 0;
            device.Write((Char)2 + "2" + "\r", 3, ref n);
        }
        private void LED3Button_Click(object sender, EventArgs e)
        {
            uint n = 0;
            device.Write((Char)2 + "3" + "\r", 3, ref n);
        }
        private void TickPassed(object sender, EventArgs e)
        {
            GetStatus();
        }
        private void TextBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode.Equals(Keys.Enter)) { e.SuppressKeyPress = true; WriteOnLCD(); }
        }
        private void GetStatus()
        {
            uint n = 0;
            device.Write((Char)1 + "\r", 2, ref n);
            n = 0;
            while (true)
            {
                uint numBytesAvailable = 0;
                device.GetRxBytesAvailable(ref numBytesAvailable);
                if (numBytesAvailable > 0) 
                {
                    string read;
                    device.Read(out read, numBytesAvailable, ref n);
                    receivedData += read; 
                    if (read[^1] == '\r')
                    {
                        SetLabels(receivedData.Split(' '));
                        receivedData = null;
                        break;
                    }
                    n = 0;
                }
            }
        }
    }
}
