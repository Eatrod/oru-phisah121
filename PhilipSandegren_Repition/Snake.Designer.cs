namespace PhilipSandegren_Repition
{
    partial class Snake
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
            this.components = new System.ComponentModel.Container();
            this.snakeScore_LBL = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.GameTick = new System.Windows.Forms.Timer(this.components);
            this.GameTimer = new System.Windows.Forms.Timer(this.components);
            this.SuspendLayout();
            // 
            // snakeScore_LBL
            // 
            this.snakeScore_LBL.AutoSize = true;
            this.snakeScore_LBL.Location = new System.Drawing.Point(13, 409);
            this.snakeScore_LBL.Name = "snakeScore_LBL";
            this.snakeScore_LBL.Size = new System.Drawing.Size(35, 13);
            this.snakeScore_LBL.TabIndex = 0;
            this.snakeScore_LBL.Text = "label1";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(75, 409);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(35, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "label2";
            // 
            // GameTick
            // 
            this.GameTick.Enabled = true;
            this.GameTick.Tick += new System.EventHandler(this.GameTick_Tick);
            // 
            // Snake
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(479, 434);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.snakeScore_LBL);
            this.DoubleBuffered = true;
            this.Name = "Snake";
            this.Text = "Snake";
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Snake_Paint);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Snake_KeyDown);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label snakeScore_LBL;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Timer GameTick;
        private System.Windows.Forms.Timer GameTimer;
    }
}