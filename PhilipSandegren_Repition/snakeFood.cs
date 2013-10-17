using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace PhilipSandegren_Repition
{
    class snakeFood
    {
            private int x, y, width, height;
            private SolidBrush brush;
            public Rectangle foodRec;
            //Skapar ett nytt mat-objekt på en slumpmässig plats
            public snakeFood()
            {
                Random randFood = new Random();
                x = randFood.Next(0, 47) * 10;
                y = randFood.Next(0, 45) * 10;
                brush = new SolidBrush(Color.Red);
                width = 10;
                height = 10;
                foodRec = new Rectangle(x, y, width, height);
            }
            //Byter plats på maten när den äts
            public void foodlocation(Random randFood)
            {
                x = randFood.Next(0, 47) * 10;
                y = randFood.Next(0, 42) * 10;

            }
            //Ritar ut maten på spelplanen
            public void drawFood(Graphics paper)
            {
                foodRec.X = x;
                foodRec.Y = y;
                paper.FillRectangle(brush, foodRec);
            }
    }
}
