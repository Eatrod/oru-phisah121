namespace PhilipSandegren_Repition
{
    partial class TicTacToe
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.button1_BL = new System.Windows.Forms.Button();
            this.button2_BL = new System.Windows.Forms.Button();
            this.button4_BL = new System.Windows.Forms.Button();
            this.button5_BL = new System.Windows.Forms.Button();
            this.button7_BL = new System.Windows.Forms.Button();
            this.button8_BL = new System.Windows.Forms.Button();
            this.button3_BL = new System.Windows.Forms.Button();
            this.button6_BL = new System.Windows.Forms.Button();
            this.button9_BL = new System.Windows.Forms.Button();
            this.turn_LBL = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // button1_BL
            // 
            this.button1_BL.Location = new System.Drawing.Point(36, 25);
            this.button1_BL.Name = "button1_BL";
            this.button1_BL.Size = new System.Drawing.Size(87, 64);
            this.button1_BL.TabIndex = 0;
            this.button1_BL.UseVisualStyleBackColor = true;
            this.button1_BL.Click += new System.EventHandler(this.button1_BL_Click);
            // 
            // button2_BL
            // 
            this.button2_BL.Location = new System.Drawing.Point(149, 25);
            this.button2_BL.Name = "button2_BL";
            this.button2_BL.Size = new System.Drawing.Size(87, 64);
            this.button2_BL.TabIndex = 1;
            this.button2_BL.UseVisualStyleBackColor = true;
            // 
            // button4_BL
            // 
            this.button4_BL.Location = new System.Drawing.Point(36, 98);
            this.button4_BL.Name = "button4_BL";
            this.button4_BL.Size = new System.Drawing.Size(87, 64);
            this.button4_BL.TabIndex = 2;
            this.button4_BL.UseVisualStyleBackColor = true;
            // 
            // button5_BL
            // 
            this.button5_BL.Location = new System.Drawing.Point(149, 98);
            this.button5_BL.Name = "button5_BL";
            this.button5_BL.Size = new System.Drawing.Size(87, 64);
            this.button5_BL.TabIndex = 3;
            this.button5_BL.UseVisualStyleBackColor = true;
            this.button5_BL.Click += new System.EventHandler(this.button4_Click);
            // 
            // button7_BL
            // 
            this.button7_BL.Location = new System.Drawing.Point(36, 179);
            this.button7_BL.Name = "button7_BL";
            this.button7_BL.Size = new System.Drawing.Size(87, 64);
            this.button7_BL.TabIndex = 4;
            this.button7_BL.UseVisualStyleBackColor = true;
            // 
            // button8_BL
            // 
            this.button8_BL.Location = new System.Drawing.Point(149, 179);
            this.button8_BL.Name = "button8_BL";
            this.button8_BL.Size = new System.Drawing.Size(87, 64);
            this.button8_BL.TabIndex = 5;
            this.button8_BL.UseVisualStyleBackColor = true;
            // 
            // button3_BL
            // 
            this.button3_BL.Location = new System.Drawing.Point(263, 25);
            this.button3_BL.Name = "button3_BL";
            this.button3_BL.Size = new System.Drawing.Size(87, 64);
            this.button3_BL.TabIndex = 6;
            this.button3_BL.UseVisualStyleBackColor = true;
            // 
            // button6_BL
            // 
            this.button6_BL.Location = new System.Drawing.Point(263, 98);
            this.button6_BL.Name = "button6_BL";
            this.button6_BL.Size = new System.Drawing.Size(87, 64);
            this.button6_BL.TabIndex = 7;
            this.button6_BL.UseVisualStyleBackColor = true;
            // 
            // button9_BL
            // 
            this.button9_BL.Location = new System.Drawing.Point(263, 179);
            this.button9_BL.Name = "button9_BL";
            this.button9_BL.Size = new System.Drawing.Size(87, 64);
            this.button9_BL.TabIndex = 8;
            this.button9_BL.UseVisualStyleBackColor = true;
            // 
            // turn_LBL
            // 
            this.turn_LBL.AutoSize = true;
            this.turn_LBL.Location = new System.Drawing.Point(482, 41);
            this.turn_LBL.Name = "turn_LBL";
            this.turn_LBL.Size = new System.Drawing.Size(35, 13);
            this.turn_LBL.TabIndex = 9;
            this.turn_LBL.Text = "label1";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(475, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(32, 13);
            this.label1.TabIndex = 10;
            this.label1.Text = "Turn:";
            // 
            // TicTacToe
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(679, 278);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.turn_LBL);
            this.Controls.Add(this.button9_BL);
            this.Controls.Add(this.button6_BL);
            this.Controls.Add(this.button3_BL);
            this.Controls.Add(this.button8_BL);
            this.Controls.Add(this.button7_BL);
            this.Controls.Add(this.button5_BL);
            this.Controls.Add(this.button4_BL);
            this.Controls.Add(this.button2_BL);
            this.Controls.Add(this.button1_BL);
            this.Name = "TicTacToe";
            this.Text = "TicTacToe";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1_BL;
        private System.Windows.Forms.Button button2_BL;
        private System.Windows.Forms.Button button4_BL;
        private System.Windows.Forms.Button button5_BL;
        private System.Windows.Forms.Button button7_BL;
        private System.Windows.Forms.Button button8_BL;
        private System.Windows.Forms.Button button3_BL;
        private System.Windows.Forms.Button button6_BL;
        private System.Windows.Forms.Button button9_BL;
        private System.Windows.Forms.Label turn_LBL;
        private System.Windows.Forms.Label label1;
    }
}