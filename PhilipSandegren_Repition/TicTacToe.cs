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
            turnLBL();
        }
        bool xTurn = true;

        public void reset()
        {
            //Återställer knapparna
            button1_BL.Text = null; button1_BL.Enabled = true; button1_BL.BackColor = Color.WhiteSmoke;
            button2_BL.Text = null; button2_BL.Enabled = true; button2_BL.BackColor = Color.WhiteSmoke;
            button3_BL.Text = null; button3_BL.Enabled = true; button3_BL.BackColor = Color.WhiteSmoke;
            button4_BL.Text = null; button4_BL.Enabled = true; button4_BL.BackColor = Color.WhiteSmoke;
            button5_BL.Text = null; button5_BL.Enabled = true; button5_BL.BackColor = Color.WhiteSmoke;
            button6_BL.Text = null; button6_BL.Enabled = true; button6_BL.BackColor = Color.WhiteSmoke;
            button7_BL.Text = null; button7_BL.Enabled = true; button7_BL.BackColor = Color.WhiteSmoke;
            button8_BL.Text = null; button8_BL.Enabled = true; button8_BL.BackColor = Color.WhiteSmoke;
            button9_BL.Text = null; button9_BL.Enabled = true; button9_BL.BackColor = Color.WhiteSmoke;
            //ÅTerställer variabler
            xTurn = true;
            turnLBL();
        }

        public void victory_check()
        {
            //Kollar om någon vunnit i första raden
            if (button1_BL.Text == "X")
                if (button2_BL.Text == "X")
                    if (button3_BL.Text == "X")
                    {
                        button1_BL.BackColor = Color.LawnGreen;
                        button2_BL.BackColor = Color.LawnGreen;
                        button3_BL.BackColor = Color.LawnGreen;
                        MessageBox.Show("X Vann!");
                    }
            if (button1_BL.Text == "O")
                if (button2_BL.Text == "O")
                    if (button3_BL.Text == "O")
                    {
                        button1_BL.BackColor = Color.LawnGreen;
                        button2_BL.BackColor = Color.LawnGreen;
                        button3_BL.BackColor = Color.LawnGreen;
                        MessageBox.Show("O Vann!");
                    }
            //Kollar om någon vunnit i andra raden
            if (button4_BL.Text == "X")
                if (button5_BL.Text == "X")
                    if (button6_BL.Text == "X")
                    {
                        button4_BL.BackColor = Color.LawnGreen;
                        button5_BL.BackColor = Color.LawnGreen;
                        button6_BL.BackColor = Color.LawnGreen;
                        MessageBox.Show("X Vann!");
                    }
            if (button4_BL.Text == "O")
                if (button5_BL.Text == "O")
                    if (button6_BL.Text == "O")
                    {
                        button4_BL.BackColor = Color.LawnGreen;
                        button5_BL.BackColor = Color.LawnGreen;
                        button6_BL.BackColor = Color.LawnGreen;
                        MessageBox.Show("O Vann!");
                    }
            //Kollar om någon vunnit i tredje raden
            if (button7_BL.Text == "X")
                if (button8_BL.Text == "X")
                    if (button9_BL.Text == "X")
                    {
                        button7_BL.BackColor = Color.LawnGreen;
                        button8_BL.BackColor = Color.LawnGreen;
                        button9_BL.BackColor = Color.LawnGreen;
                        MessageBox.Show("X Vann!");
                    }
            if (button7_BL.Text == "O")
                if (button8_BL.Text == "O")
                    if (button9_BL.Text == "O")
                    {
                        button7_BL.BackColor = Color.LawnGreen;
                        button8_BL.BackColor = Color.LawnGreen;
                        button9_BL.BackColor = Color.LawnGreen;
                        MessageBox.Show("O Vann!");
                    }
            //Kollar om någon vunnit i första kolumnen
            if (button1_BL.Text == "X")
                if (button4_BL.Text == "X")
                    if (button7_BL.Text == "X")
                    {
                        button1_BL.BackColor = Color.LawnGreen;
                        button4_BL.BackColor = Color.LawnGreen;
                        button7_BL.BackColor = Color.LawnGreen;
                        MessageBox.Show("X Vann!");
                    }
            if (button1_BL.Text == "O")
                if (button4_BL.Text == "O")
                    if (button7_BL.Text == "O")
                    {
                        button1_BL.BackColor = Color.LawnGreen;
                        button4_BL.BackColor = Color.LawnGreen;
                        button7_BL.BackColor = Color.LawnGreen;
                        MessageBox.Show("O Vann!");
                    }
            //Kollar om någon vunnit i andra kolumnen
            if (button2_BL.Text == "X")
                if (button5_BL.Text == "X")
                    if (button8_BL.Text == "X")
                    {
                        button2_BL.BackColor = Color.LawnGreen;
                        button5_BL.BackColor = Color.LawnGreen;
                        button8_BL.BackColor = Color.LawnGreen;
                        MessageBox.Show("X Vann!");
                    }
            if (button2_BL.Text == "O")
                if (button5_BL.Text == "O")
                    if (button8_BL.Text == "O")
                    {
                        button2_BL.BackColor = Color.LawnGreen;
                        button5_BL.BackColor = Color.LawnGreen;
                        button8_BL.BackColor = Color.LawnGreen;
                        MessageBox.Show("O Vann!");
                    }
            //Kollar om någon vunnit i tredje kolumnen
            if (button3_BL.Text == "X")
                if (button6_BL.Text == "X")
                    if (button9_BL.Text == "X")
                    {
                    }
            if (button3_BL.Text == "O")
                if (button6_BL.Text == "O")
                    if (button9_BL.Text == "O")
                    {
                    }
            //Kollar om någon vunnit i Första krysset
            if (button1_BL.Text == "X")
                if (button5_BL.Text == "X")
                    if (button9_BL.Text == "X")
                    {
                    }
            if (button1_BL.Text == "O")
                if (button5_BL.Text == "O")
                    if (button9_BL.Text == "O")
                    {
                    }
            //Kollar om någon vunnit i Andra krysset
            if (button3_BL.Text == "X")
                if (button5_BL.Text == "X")
                    if (button7_BL.Text == "X")
                    {
                    }
            if (button3_BL.Text == "O")
                if (button5_BL.Text == "O")
                    if (button7_BL.Text == "O")
                    {
                    }
            //Kollar om det blev oavgjort
            if (button1_BL.Text != null)
                if (button2_BL.Text != null)
                    if (button3_BL.Text != null)
                        if (button4_BL.Text != null)
                            if (button5_BL.Text != null)
                                if (button6_BL.Text != null)
                                    if (button7_BL.Text != null)
                                        if (button8_BL.Text != null)
                                            if (button9_BL.Text != null)
                                            {
                                            }
                        

        }

        public void turnLBL()
        {
            if (xTurn == true)
                turn_LBL.Text = "X";
            else
                turn_LBL.Text = "O";
        }
        //Button 1
        private void button1_BL_Click(object sender, EventArgs e)
        {
            if (xTurn == true)
            {
                button1_BL.Text = "X";
                xTurn = false;
            }
            else
            {
                button1_BL.Text = "O";
                xTurn = true;
            }
            button1_BL.Enabled = false;
            turnLBL();
            victory_check();
        }

        //Button 2
        private void button2_BL_Click(object sender, EventArgs e)
        {
            if (xTurn == true)
            {
                button2_BL.Text = "X";
                xTurn = false;
            }
            else
            {
                button2_BL.Text = "O";
                xTurn = true;
            }
            button2_BL.Enabled = false;
            victory_check();
            turnLBL();
        }
        //Button 3
        private void button3_BL_Click(object sender, EventArgs e)
        {
            if (xTurn == true)
            {
                button3_BL.Text = "X";
                xTurn = false;
            }
            else
            {
                button3_BL.Text = "O";
                xTurn = true;
            }
            button3_BL.Enabled = false;
            victory_check();
            turnLBL();
        }
        //Button 4
        private void button4_BL_Click(object sender, EventArgs e)
        {
            if (xTurn == true)
            {
                button4_BL.Text = "X";
                xTurn = false;
            }
            else
            {
                button4_BL.Text = "O";
                xTurn = true;
            }
            button4_BL.Enabled = false;
            victory_check();
            turnLBL();
        }
        //Button 5
        private void button5_BL_Click(object sender, EventArgs e)
        {
            if (xTurn == true)
            {
                button5_BL.Text = "X";
                xTurn = false;
            }
            else
            {
                button5_BL.Text = "O";
                xTurn = true;
            }
            button5_BL.Enabled = false;
            victory_check();
            turnLBL();
        }
        //Button 6
        private void button6_BL_Click(object sender, EventArgs e)
        {
            if (xTurn == true)
            {
                button6_BL.Text = "X";
                xTurn = false;
            }
            else
            {
                button6_BL.Text = "O";
                xTurn = true;
            }
            button6_BL.Enabled = false;
            victory_check();
            turnLBL();
        }
        //Button 7
        private void button7_BL_Click(object sender, EventArgs e)
        {
            if (xTurn == true)
            {
                button7_BL.Text = "X";
                xTurn = false;
            }
            else
            {
                button7_BL.Text = "O";
                xTurn = true;
            }
            button7_BL.Enabled = false;
            victory_check();
            turnLBL();
        }
        //Button 8
        private void button8_BL_Click(object sender, EventArgs e)
        {
            if (xTurn == true)
            {
                button8_BL.Text = "X";
                xTurn = false;
            }
            else
            {
                button8_BL.Text = "O";
                xTurn = true;
            }
            button8_BL.Enabled = false;
            victory_check();
            turnLBL();
        }
        //Button 9
        private void button9_BL_Click(object sender, EventArgs e)
        {
            if (xTurn == true)
            {
                button9_BL.Text = "X";
                xTurn = false;
            }
            else
            {
                button9_BL.Text = "O";
                xTurn = true;
            }
            button9_BL.Enabled = false;
            victory_check();
            turnLBL();
        }

        private void reset_BL_Click(object sender, EventArgs e)
        {
            reset();
        }
    }
}
