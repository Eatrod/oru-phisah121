using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PhilipSandegren_Repition
{
    public partial class TicTacToe : Form
    {
        public TicTacToe()
        {
            InitializeComponent();
        }
        bool xTurn = true;
        public void turn_check()
        {

        }
        private void button4_Click(object sender, EventArgs e)
        {

        }

        private void button1_BL_Click(object sender, EventArgs e)
        {
            if (xTurn == true)
            {
                button1_BL.Text = "X";
            }
            else
                button1_BL.Text = "O";
            button1_BL.Enabled = false;
        }
    }
}
