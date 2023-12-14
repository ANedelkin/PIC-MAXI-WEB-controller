using System;
using System.IO.Ports;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PIC_MAXI_WEB_controller
{
    public partial class Form1 : Form
    {
        SerialPort port;
        bool connected = false;
        int pIndex;
        public Form1()
        {
            InitializeComponent();
            port = new SerialPort
            {
                BaudRate = 115200,
                Parity = Parity.None,
                DataBits = 8,
                StopBits = StopBits.One,
                Handshake = Handshake.None
            };
            port.DataReceived += new SerialDataReceivedEventHandler(DataReceived);
            this.FormBorderStyle = FormBorderStyle.FixedSingle;
        }

        private void SendBttn_Click(object sender, EventArgs e)
        {
            if (!port.IsOpen) { port.Open(); }
            string text = TextBox.Text;
            if (text.Length >= 16) { text = text.Insert(16, "\r\n"); }
            port.Write('l' + text + (Char)3);
            TextBox.Text = "";
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            string[] ports = SerialPort.GetPortNames();
            COMDropDown.Items.AddRange(ports);
            pIndex = COMDropDown.SelectedIndex;
        }
        private async void COMPortSelected(object sender, EventArgs e)
        {
            if (COMDropDown.SelectedIndex != pIndex)
            {
                var cancel = new CancellationTokenSource();
                port.Close();
                port.PortName = COMDropDown.Text;
                Task task = Task.Run(() =>
                {
                    try { port.Open(); }
                    catch { }
                    for (int i = 0; i < 100 && !connected; i++) { Thread.Sleep(10); }
                }, cancel.Token);
                await Task.WhenAny(task, Task.Delay(100));
                if (!task.IsCompleted)
                {
                    cancel.Cancel();
                    MessageBox.Show("The application failed to connect to the port you selected.\n" +
                                    "Ensure that you select the port the board is connected to.",
                                    "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    COMDropDown.SelectedIndex = pIndex;
                }
                else
                {
                    DisplayPanel.Enabled = true;
                    LEDGroupBox.Enabled = true;
                    ADCGroupBox.Enabled = true;
                    ButtonsGroupBox.Enabled = true;
                    pIndex = COMDropDown.SelectedIndex;
                }
            }
        }

        private void LED1Button_Click(object sender, EventArgs e)
        {
            if (!port.IsOpen) { port.Open(); }
            string text = 'd' + "1" + (Char)3;
            port.Write(text);
        }
        private void LED2Button_Click(object sender, EventArgs e)
        {
            if (!port.IsOpen) { port.Open(); }
            port.Write('d' + "2" + (Char)3);
        }
        private void LED3Button_Click(object sender, EventArgs e)
        {
            if (!port.IsOpen) { port.Open(); }
            port.Write('d' + "3" + (Char)3);
        }
        private void DataReceived(object sender, EventArgs e)
        {
            connected = true;
            receivedData += port.ReadExisting();
            if (receivedData[^1] == (Char)3)
            {
                SetLabels(receivedData.Split(' '));
                receivedData = null;
            }
        }
        public void Connect()
        {
            port.Open(); 
            while (!connected);
            /*Thread thread = new Thread(() => {
                try { port.Open(); while (!connected) ; }
                catch { }
            });

            thread.Start();
            if (!thread.Join(750))
            {
                COMDropDown.SelectedIndex = pIndex;
                MessageBox.Show("The application failed to connect to the port you selected.\n" +
                                    "Ensure that you select the port the board is connected to.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                thread.Abort();
            }*/
        }
    }
}
