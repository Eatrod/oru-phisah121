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
    //Huvudklass för huvudmenyn och undermenyer
    public partial class Spel : Form
    {
        public Snake Snake { get; set; }
        public int X { get; set; }
        public int Y { get; set; }
        public int Misses { get; set; }
        public int Game_Time { get; set; }
        public int Score { get; set; }
        bool hidden = false;
        public Spel()
        {
            InitializeComponent();
            Snake = new Snake(this);
        }
        public void ShowHide_meny()
        {
            if (hidden == false)
            {
                Newgame_BL.Visible = false;
                Options_BL.Visible = false;
                Exit_BL.Visible = false;
                Mainpicture_PB.Visible = false;
                Snake_BL.Visible = true;
                Snake_BL.Enabled = true;
                Game_T.Enabled = true;
                hidden = true;
            }
            else
            {
                Newgame_BL.Visible = true;
                Options_BL.Visible = true;
                Exit_BL.Visible = true;
                Mainpicture_PB.Visible = true;
                Game_T.Enabled = false;
                Timer_LBL.Visible = false;
                Score_LBL.Visible = false;
                Snake_BL.Visible = false;
                Snake_BL.Enabled = false;
                hidden = false;
            }
        }

        private void Newgame_BL_Click(object sender, EventArgs e)
        {
            //Gömmer huvudmenyn
            ShowHide_meny();
        }

        private void Spel_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Escape)
                ShowHide_meny();
        }

        private void Exit_BL_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
        private void Snake_BL_Click(object sender, System.EventArgs e)
        {
            this.Snake.Spel_StartSnake();    
        }


    }
    //Klass för spelet Snake
    public class Snake
    {
        public int X { get; set; }
        public int Y { get; set; }
        private Spel spel = null;

        public Snake()
        {
    
        }

        public Snake(Spel spel)
        {
            this.spel = spel;
        }

        private void Game_T_Tick(object sender, EventArgs e)
        {
            spel.Game_Time += 1;
            spel.Timer_LBL.Text = "Time: " + Convert.ToString(spel.Game_Time);
            this.spel.Invalidate();
        }
        public void Spel_StartSnake()
        {
            spel.Game_T.Enabled = true;
            spel.Timer_LBL.Visible = true;
            spel.Score_LBL.Visible = true;
            System.Drawing.Pen myPen;
            myPen = new System.Drawing.Pen(System.Drawing.Color.Red);
            System.Drawing.Graphics formGraphics = spel.CreateGraphics();
            formGraphics.DrawLine(myPen, 0, 0, 200, 200);
            this.spel.Invalidate();
        }
    }
    //Klass för spelet Asteroid
    public class Asteroid
    {
        public int X { get; set; }
        public int Y { get; set; }
        private Spel spel = null;

        public Asteroid()
        {

        }

        public Asteroid(Spel spel)
        {
            this.spel = spel;
        }

        private void Game_T_Tick(object sender, EventArgs e)
        {
            spel.Game_Time += 1;
            spel.Timer_LBL.Text = "Time: " + Convert.ToString(spel.Game_Time);
        }
        public void Spel_StartAsteroid()
        {
            spel.Timer_LBL.Visible = true;
            spel.Game_T.Enabled = true;
            Graphics g = this.spel.CreateGraphics();
            this.spel.Invalidate();
        }
    }
}
