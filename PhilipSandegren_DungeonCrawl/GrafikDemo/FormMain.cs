using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Media;

namespace GrafikDemo
{
    public partial class FormMain : Form
    {
        //Skapar alla variabler även om ¨många av dessa borde ligga i en klass
        public int posX { get; set; }
        public int posY { get; set; }
        Random ran = new Random(DateTime.Now.Millisecond);
        Pen blackPen = new Pen(Color.Black, 2);
        Brush blackBrush = new SolidBrush(Color.Black);
        myRectangle mainRect = new myRectangle();
        myRectangle secRect = new myRectangle();
        myRectangle thirdRect = new myRectangle();
        myRectangle fourRect = new myRectangle();
        myRectangle dummyRect = new myRectangle();
        List<myRectangle> listRect = new List<myRectangle>();

        //Kollar om två rektanglar krockar
        public void rectangleCollisionCheck()
        {
            for (int i = 0; i < listRect.Count; i++)
            {
                myRectangle rect = listRect[i];
                for (int j = i+1; j < listRect.Count; j++)
                {
                    myRectangle rect2 = listRect[j];
                    float wy = (rect.r.Width + rect2.r.Width) * (rect.r.Y + 50 - rect2.r.Y + 50);
                    float hx = (rect.r.Height + rect2.r.Height) * (rect.r.X + 50 - rect2.r.X + 50);
                    if (Rectangle.Intersect(rect.r,rect2.r) != Rectangle.Empty)
                    {
                        if (wy > hx) {
                            if (wy > -hx) {
                                speedReverseY(rect);
                                speedReverseY(rect2);
                            }
                            else {
                               speedReverseX(rect);
                               speedReverseX(rect2);
                            }
                        }
                        else {
                            if (wy > -hx)
                            {
                                speedReverseX(rect);
                                speedReverseX(rect2);
                            }
                            else
                            {
                                speedReverseY(rect);
                                speedReverseY(rect2);
                            }
                        }
                    }
                }
            }
          
        }
        void speedReverseX(myRectangle r)
        {
            if (r.speedX >= 0)
                r.speedX = -5;
            else
                r.speedX = 5;
        }
        void speedReverseY(myRectangle r)
        {
            if (r.speedY >= 0)
                r.speedY = -5;
            else
                r.speedY = 5;
        }
        //Sätter värden till defualt
        public FormMain()
        {
            InitializeComponent();
            mainRect.r.X = 601; mainRect.r.Y = 400; mainRect.r.Width = 100; mainRect.r.Height = 100;
            secRect.r.X = 100; secRect.r.Y = 150; secRect.r.Width = 100; secRect.r.Height = 100;
            thirdRect.r.X = 300; thirdRect.r.Y = 350; thirdRect.r.Width = 100; thirdRect.r.Height = 100;
            fourRect.r.X = 300; fourRect.r.Y = 500; fourRect.r.Width = 100; fourRect.r.Height = 100;
            //Lägger till alla rektanglar i rektangel listan
            listRect.Add(mainRect);
            listRect.Add(secRect);
            listRect.Add(thirdRect);
            listRect.Add(fourRect);
            this.Invalidate();
        }
        //Uppdaterar rektanglarnas position
        public void updatePosition()
        {
            foreach (var rect in listRect)
            {
                rect.r.X += rect.speedX;
                rect.r.Y += rect.speedY;
                this.Invalidate();
            }
        }
        //Loopar igenom rektanglarna för att kolla om någon försöker gå utanför fönstret
        public void outsideCollisionCheck()
        {
            foreach (var rect in listRect)
            {
                //En rektangels Y försöker bli större än fönstret uppåt
                if (rect.r.Y <= 5)
                {
                    rect.speedY = 5;
                }

                //En rektangels X försöker bli mindre än fönstret vänster
                if (rect.r.X <= 5)
                {
                    rect.speedX = 5;
                }

                //En rektangels X försöker bli större än fönstret höger
                if (rect.r.X >= 750)
                {
                    rect.speedX = -5;
                }

                //En rektangels Y försöker bli större än fönstret neråt
                if (rect.r.Y >= 520)
                {
                    rect.speedY = -5;
                }
            }
        }

        //Ritar ut båda rektanglarna
        private void FormMain_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            foreach (var rect in listRect)
            {
                g.DrawRectangle(blackPen, rect.r);
                g.FillRectangle(blackBrush, rect.r);
            }
        }

        //Flyttar en av rektanglarna till musens postion
        private void FormMain_MouseClick(object sender, MouseEventArgs e)
        {
            posX = e.X;
            posY = e.Y;
            mainRect.r.X = posX;
            mainRect.r.Y = posY;
            this.Invalidate();
        }

        //Läser av om användaren vill styra rektangeln
        private void FormMain_KeyDown(object sender, KeyEventArgs e)
        {
            updatePosition();
        }

        //Vid varje klocktick så kommer rektanglarna att röra sig
        private void GameTick_Tick(object sender, EventArgs e)
        {
            outsideCollisionCheck();
            rectangleCollisionCheck();
            updatePosition();
        }
    }
}
