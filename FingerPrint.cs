using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.IO;
using System.Net;
using MySql.Data.MySqlClient;
namespace FingerPrint
{
    public partial class FingerPrint : Form
    {
        private SerialPort myport;
        private string in_data;
        //private MySqlConnection mc;
        public FingerPrint()
        {
            InitializeComponent();
            
            
        }

        private void enroll_Click(object sender, EventArgs e)
        {
            myport.WriteLine("e");
            myport.WriteLine(ide.Text);
            
            display.AppendText("Please Keep your Finger \n");
           /* MySqlCommand enrollcommand = new MySqlCommand("insert into sensors (id,name,value) VALUES ('" + ide.Text + "','" + name.Text + "','0')", mc);
            enrollcommand.ExecuteNonQuery();*/
            
            ide.Text = " ";
           
            name.Text = "";
        }

        private void myport_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            in_data = myport.ReadLine();
            this.Invoke(new EventHandler(displaydata_event));
            
            
        }

        private void displaydata_event(object sender, EventArgs e)
        {
            display.AppendText(in_data+"\n");
        }

        

        

        private void match_Click(object sender, EventArgs e)
        {
            myport.WriteLine("m");
            //int va =
           // MySqlCommand match = new MySqlCommand("update sensors set value='"+ValueType+"'where id='"+ide.Text+"'",mc);
            //display.Text = "Keep your Finger on FingerPrint\n";
            display.AppendText("Keep your Finger on FingerPrint\n");
           /* DataTable dt = new DataTable();
            MySqlDataAdapter adp = new MySqlDataAdapter("select value from sensors where id='"+ide.Text+"'",mc);
            adp.Fill(dt);
            int va = Convert.ToInt32(dt.Rows[0][2]);
            int re = va + 40;*/
           // int value = Convert.ToInt32(myport.ReadLine());

        }

        private void delete_Click(object sender, EventArgs e)
        {

            myport.WriteLine("d");
            myport.WriteLine(idd.Text);
            display.AppendText("Deleted FingerPrint with ID "+idd.Text+"\n");
           /* MySqlCommand deletecomm = new MySqlCommand("DELETE FROM sensors WHERE id='"+ idd.Text + "'", mc);
            deletecomm.ExecuteNonQuery();*/
            idd.Text = "";
            
        }

        private void start_Click(object sender, EventArgs e)
        {
            myport = new SerialPort();
            myport.BaudRate = 9600;
            myport.PortName = "COM1";
            myport.Parity = Parity.None;
            myport.DataBits = 8;
            myport.StopBits = StopBits.One;
            myport.DataReceived += myport_DataReceived;
            try
            {
                myport.Open();
                display.Text = "PORT OPENED\n";
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error");
            }
           /* string conn = "server=localhost;database=arduino;uid=root;pwd= ;";
            mc = new MySqlConnection(conn);

            try
            {
                mc.Open();
                // MessageBox.Show("connection Succesful");

                // mc.Close();
            }
            catch (Exception ex)
            {
                // MessageBox.Show("connection failed" + ex);
            }*/
        }

        private void stop_Click(object sender, EventArgs e)
        {
            myport.Close();
            //mc.Close();
            display.AppendText("PORT CLOSED\n");
            
        }

        

       

        
    }
}
