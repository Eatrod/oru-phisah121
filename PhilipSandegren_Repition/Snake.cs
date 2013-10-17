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
    public partial class Snake : Form
    {
        public void restart()
        {
            score = 0;
            MessageBox.Show("Spelet är slut");
        }
        public void collision()
        {
            for (int i = 1; i < snakes.SnakeRec.Length; i++)
            {
                if (snakes.SnakeRec[0].IntersectsWith(snakes.SnakeRec[1]))
                {
                    restart();
                }
            }
            if (snakes.SnakeRec[0].X < 0 || snakes.SnakeRec[0].X > 290)
            {
                restart();

            }
            if (snakes.SnakeRec[0].Y < 0 || snakes.SnakeRec[0].Y > 290)
            {
                restart();
            }

        }


        Graphics paper;
        public int score { get; set; }
        bool down; bool up; bool left; bool right;
        snakeTheSnake snakes = new snakeTheSnake();
        Random randFood = new Random();
        snakeFood food = new snakeFood();
        public Snake()
        {
            InitializeComponent();
        }

        private void Snake_Paint(object sender, PaintEventArgs e)
        {
            paper = e.Graphics;
            food.drawFood(paper);
            snakes.drawSnake(paper);
        }

        private void GameTick_Tick(object sender, EventArgs e)
        {
            snakeScore_LBL.Text = "Score: " + Convert.ToString(score);
            if (down == true) 
            { 
                snakes.moveDown(); 
            }
            if (up == true) 
            {
                snakes.moveUp(); 
            }
            if (right == true) 
            { 
                snakes.moveRight(); 
            }
            if (left == true) 
            { 
                snakes.moveLeft(); 
            }
            this.Invalidate();
            collision();
            for (int i = 0; i < snakes.SnakeRec.Length; i++)
            {
                if (snakes.SnakeRec[i].IntersectsWith(food.foodRec))
                {
                    score += 1;
                    snakes.growSnake();
                    food.foodlocation(randFood);
                }
            }
        }

        private void Snake_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyData == Keys.Space)
            {
                GameTick.Enabled = true;
                down = false;
                up = false;
                left = false;
                right = true;
            }
            if (e.KeyData == Keys.Down && up == false)
            {
                down = true;
                up = false;
                right = false;
                left = false;
            }
            if (e.KeyData == Keys.Up && down == false)
            {
                down = false;
                up = true;
                right = false;
                left = false;
            }
            if (e.KeyData == Keys.Left && right == false)
            {
                down = false;
                up = false;
                right = false;
                left = true;
            }
            if (e.KeyData == Keys.Right && left == false)
            {
                down = false;
                up = false;
                right = true;
                left = false;
            }
        }
    }
}
