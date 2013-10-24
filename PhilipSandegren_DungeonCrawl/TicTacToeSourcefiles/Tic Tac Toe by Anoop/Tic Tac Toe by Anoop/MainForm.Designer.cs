/*
 * Created by SharpDevelop.
 * Developer:Anoop Kumar Sharma
 * Date: 9/3/2013
 * Time: 12:37 PM
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
namespace Tic_Tac_Toe_by_Anoop
{
	partial class MainForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		
		/// <summary>
		/// Disposes resources used by the form.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing) {
				if (components != null) {
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}
		
		/// <summary>
		/// This method is required for Windows Forms designer support.
		/// Do not change the method contents inside the source code editor. The Forms designer might
		/// not be able to load this method if it was changed manually.
		/// </summary>
		private void InitializeComponent()
		{
			this.button1 = new System.Windows.Forms.Button();
			this.button2 = new System.Windows.Forms.Button();
			this.button3 = new System.Windows.Forms.Button();
			this.button4 = new System.Windows.Forms.Button();
			this.button5 = new System.Windows.Forms.Button();
			this.button6 = new System.Windows.Forms.Button();
			this.button7 = new System.Windows.Forms.Button();
			this.button8 = new System.Windows.Forms.Button();
			this.button9 = new System.Windows.Forms.Button();
			this.label1 = new System.Windows.Forms.Label();
			this.displayturn = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.label3 = new System.Windows.Forms.Label();
			this.player1score = new System.Windows.Forms.Label();
			this.player2score = new System.Windows.Forms.Label();
			this.reset = new System.Windows.Forms.Button();
			this.playagain = new System.Windows.Forms.Button();
			this.label4 = new System.Windows.Forms.Label();
			this.label5 = new System.Windows.Forms.Label();
			this.label6 = new System.Windows.Forms.Label();
			this.SuspendLayout();
			// 
			// button1
			// 
			this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.button1.Location = new System.Drawing.Point(12, 12);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(69, 53);
			this.button1.TabIndex = 0;
			this.button1.UseVisualStyleBackColor = true;
			this.button1.Click += new System.EventHandler(this.Button1Click);
			// 
			// button2
			// 
			this.button2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.button2.Location = new System.Drawing.Point(87, 12);
			this.button2.Name = "button2";
			this.button2.Size = new System.Drawing.Size(69, 53);
			this.button2.TabIndex = 1;
			this.button2.UseVisualStyleBackColor = true;
			this.button2.Click += new System.EventHandler(this.Button2Click);
			// 
			// button3
			// 
			this.button3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.button3.Location = new System.Drawing.Point(162, 12);
			this.button3.Name = "button3";
			this.button3.Size = new System.Drawing.Size(69, 53);
			this.button3.TabIndex = 2;
			this.button3.UseVisualStyleBackColor = true;
			this.button3.Click += new System.EventHandler(this.Button3Click);
			// 
			// button4
			// 
			this.button4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.button4.Location = new System.Drawing.Point(12, 71);
			this.button4.Name = "button4";
			this.button4.Size = new System.Drawing.Size(69, 53);
			this.button4.TabIndex = 3;
			this.button4.UseVisualStyleBackColor = true;
			this.button4.Click += new System.EventHandler(this.Button4Click);
			// 
			// button5
			// 
			this.button5.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.button5.Location = new System.Drawing.Point(87, 71);
			this.button5.Name = "button5";
			this.button5.Size = new System.Drawing.Size(69, 53);
			this.button5.TabIndex = 4;
			this.button5.UseVisualStyleBackColor = true;
			this.button5.Click += new System.EventHandler(this.Button5Click);
			// 
			// button6
			// 
			this.button6.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.button6.Location = new System.Drawing.Point(162, 71);
			this.button6.Name = "button6";
			this.button6.Size = new System.Drawing.Size(69, 53);
			this.button6.TabIndex = 5;
			this.button6.UseVisualStyleBackColor = true;
			this.button6.Click += new System.EventHandler(this.Button6Click);
			// 
			// button7
			// 
			this.button7.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.button7.Location = new System.Drawing.Point(12, 130);
			this.button7.Name = "button7";
			this.button7.Size = new System.Drawing.Size(69, 53);
			this.button7.TabIndex = 6;
			this.button7.UseVisualStyleBackColor = true;
			this.button7.Click += new System.EventHandler(this.Button7Click);
			// 
			// button8
			// 
			this.button8.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.button8.Location = new System.Drawing.Point(87, 130);
			this.button8.Name = "button8";
			this.button8.Size = new System.Drawing.Size(69, 53);
			this.button8.TabIndex = 7;
			this.button8.UseVisualStyleBackColor = true;
			this.button8.Click += new System.EventHandler(this.Button8Click);
			// 
			// button9
			// 
			this.button9.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.button9.Location = new System.Drawing.Point(162, 130);
			this.button9.Name = "button9";
			this.button9.Size = new System.Drawing.Size(69, 53);
			this.button9.TabIndex = 8;
			this.button9.UseVisualStyleBackColor = true;
			this.button9.Click += new System.EventHandler(this.Button9Click);
			// 
			// label1
			// 
			this.label1.BackColor = System.Drawing.Color.SkyBlue;
			this.label1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label1.Location = new System.Drawing.Point(237, 12);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(100, 23);
			this.label1.TabIndex = 9;
			this.label1.Text = "Turn";
			this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// displayturn
			// 
			this.displayturn.BackColor = System.Drawing.Color.White;
			this.displayturn.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.displayturn.ForeColor = System.Drawing.Color.Black;
			this.displayturn.Location = new System.Drawing.Point(237, 34);
			this.displayturn.Name = "displayturn";
			this.displayturn.Size = new System.Drawing.Size(100, 33);
			this.displayturn.TabIndex = 10;
			this.displayturn.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// label2
			// 
			this.label2.BackColor = System.Drawing.Color.Green;
			this.label2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.label2.ForeColor = System.Drawing.Color.White;
			this.label2.Location = new System.Drawing.Point(237, 71);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(50, 23);
			this.label2.TabIndex = 11;
			this.label2.Text = "Player 1";
			this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// label3
			// 
			this.label3.BackColor = System.Drawing.Color.Green;
			this.label3.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.label3.ForeColor = System.Drawing.Color.White;
			this.label3.Location = new System.Drawing.Point(286, 71);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(51, 23);
			this.label3.TabIndex = 12;
			this.label3.Text = "Player 2";
			this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// player1score
			// 
			this.player1score.BackColor = System.Drawing.Color.White;
			this.player1score.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.player1score.ForeColor = System.Drawing.Color.Black;
			this.player1score.Location = new System.Drawing.Point(237, 93);
			this.player1score.Name = "player1score";
			this.player1score.Size = new System.Drawing.Size(50, 38);
			this.player1score.TabIndex = 13;
			this.player1score.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// player2score
			// 
			this.player2score.BackColor = System.Drawing.Color.White;
			this.player2score.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.player2score.ForeColor = System.Drawing.Color.Black;
			this.player2score.Location = new System.Drawing.Point(286, 93);
			this.player2score.Name = "player2score";
			this.player2score.Size = new System.Drawing.Size(50, 38);
			this.player2score.TabIndex = 14;
			this.player2score.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// reset
			// 
			this.reset.Location = new System.Drawing.Point(237, 136);
			this.reset.Name = "reset";
			this.reset.Size = new System.Drawing.Size(99, 23);
			this.reset.TabIndex = 15;
			this.reset.Text = "Reset Game";
			this.reset.UseVisualStyleBackColor = true;
			this.reset.Click += new System.EventHandler(this.ResetClick);
			// 
			// playagain
			// 
			this.playagain.Location = new System.Drawing.Point(237, 165);
			this.playagain.Name = "playagain";
			this.playagain.Size = new System.Drawing.Size(99, 23);
			this.playagain.TabIndex = 16;
			this.playagain.Text = "Play Again";
			this.playagain.UseVisualStyleBackColor = true;
			this.playagain.Click += new System.EventHandler(this.PlayagainClick);
			// 
			// label4
			// 
			this.label4.Location = new System.Drawing.Point(16, 194);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(100, 18);
			this.label4.TabIndex = 17;
			this.label4.Text = "Rules:";
			// 
			// label5
			// 
			this.label5.Location = new System.Drawing.Point(16, 212);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(261, 18);
			this.label5.TabIndex = 18;
			this.label5.Text = "Player1 Symbol=\"X\" and Player2 Symbol=\"O\"";
			// 
			// label6
			// 
			this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label6.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(64)))), ((int)(((byte)(0)))));
			this.label6.Location = new System.Drawing.Point(16, 230);
			this.label6.Name = "label6";
			this.label6.Size = new System.Drawing.Size(261, 19);
			this.label6.TabIndex = 19;
			this.label6.Text = "Created by Anoop Kumar Sharma";
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.SystemColors.Control;
			this.ClientSize = new System.Drawing.Size(349, 264);
			this.Controls.Add(this.label6);
			this.Controls.Add(this.label5);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.playagain);
			this.Controls.Add(this.reset);
			this.Controls.Add(this.player2score);
			this.Controls.Add(this.player1score);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.displayturn);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.button9);
			this.Controls.Add(this.button8);
			this.Controls.Add(this.button7);
			this.Controls.Add(this.button6);
			this.Controls.Add(this.button5);
			this.Controls.Add(this.button4);
			this.Controls.Add(this.button3);
			this.Controls.Add(this.button2);
			this.Controls.Add(this.button1);
			this.MaximizeBox = false;
			this.Name = "MainForm";
			this.Text = "Tic Tac Toe by Anoop";
			this.ResumeLayout(false);
		}
		private System.Windows.Forms.Label label6;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.Button playagain;
		private System.Windows.Forms.Button reset;
		private System.Windows.Forms.Label player2score;
		private System.Windows.Forms.Label player1score;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Label displayturn;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Button button9;
		private System.Windows.Forms.Button button8;
		private System.Windows.Forms.Button button7;
		private System.Windows.Forms.Button button6;
		private System.Windows.Forms.Button button5;
		private System.Windows.Forms.Button button4;
		private System.Windows.Forms.Button button3;
		private System.Windows.Forms.Button button2;
		private System.Windows.Forms.Button button1;
	}
}
