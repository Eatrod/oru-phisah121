namespace PhilipSandegren_Repition
{
    partial class Spel
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Spel));
            this.Game_T = new System.Windows.Forms.Timer(this.components);
            this.Timer_LBL = new System.Windows.Forms.Label();
            this.Score_LBL = new System.Windows.Forms.Label();
            this.Mainpicture_PB = new System.Windows.Forms.PictureBox();
            this.Exit_BL = new System.Windows.Forms.Button();
            this.Options_BL = new System.Windows.Forms.Button();
            this.Newgame_BL = new System.Windows.Forms.Button();
            this.Snake_BL = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.Mainpicture_PB)).BeginInit();
            this.SuspendLayout();
            // 
            // Game_T
            // 
            this.Game_T.Interval = 1000;
            // 
            // Timer_LBL
            // 
            this.Timer_LBL.AutoSize = true;
            this.Timer_LBL.Font = new System.Drawing.Font("Moire ExtraBold", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Timer_LBL.Location = new System.Drawing.Point(12, 539);
            this.Timer_LBL.Name = "Timer_LBL";
            this.Timer_LBL.Size = new System.Drawing.Size(0, 14);
            this.Timer_LBL.TabIndex = 5;
            this.Timer_LBL.Visible = false;
            // 
            // Score_LBL
            // 
            this.Score_LBL.AutoSize = true;
            this.Score_LBL.Font = new System.Drawing.Font("Moire ExtraBold", 8.25F, System.Drawing.FontStyle.Bold);
            this.Score_LBL.Location = new System.Drawing.Point(80, 540);
            this.Score_LBL.Name = "Score_LBL";
            this.Score_LBL.Size = new System.Drawing.Size(59, 14);
            this.Score_LBL.TabIndex = 6;
            this.Score_LBL.Text = "Score: 0";
            this.Score_LBL.Visible = false;
            // 
            // Mainpicture_PB
            // 
            this.Mainpicture_PB.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.Mainpicture_PB.Cursor = System.Windows.Forms.Cursors.Cross;
            this.Mainpicture_PB.Image = global::PhilipSandegren_Repition.Properties.Resources.Ultrashooter_text;
            this.Mainpicture_PB.InitialImage = global::PhilipSandegren_Repition.Properties.Resources.Ultrashooter_text;
            this.Mainpicture_PB.Location = new System.Drawing.Point(120, 24);
            this.Mainpicture_PB.Name = "Mainpicture_PB";
            this.Mainpicture_PB.Size = new System.Drawing.Size(618, 109);
            this.Mainpicture_PB.TabIndex = 4;
            this.Mainpicture_PB.TabStop = false;
            // 
            // Exit_BL
            // 
            this.Exit_BL.Font = new System.Drawing.Font("Miramonte", 14.25F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Exit_BL.Image = global::PhilipSandegren_Repition.Properties.Resources.button;
            this.Exit_BL.Location = new System.Drawing.Point(301, 391);
            this.Exit_BL.Name = "Exit_BL";
            this.Exit_BL.Size = new System.Drawing.Size(190, 45);
            this.Exit_BL.TabIndex = 3;
            this.Exit_BL.Text = "Exit";
            this.Exit_BL.UseVisualStyleBackColor = true;
            this.Exit_BL.Click += new System.EventHandler(this.Exit_BL_Click);
            // 
            // Options_BL
            // 
            this.Options_BL.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Options_BL.Image = global::PhilipSandegren_Repition.Properties.Resources.button;
            this.Options_BL.Location = new System.Drawing.Point(301, 280);
            this.Options_BL.Name = "Options_BL";
            this.Options_BL.Size = new System.Drawing.Size(190, 50);
            this.Options_BL.TabIndex = 2;
            this.Options_BL.Text = "Options";
            this.Options_BL.UseVisualStyleBackColor = true;
            // 
            // Newgame_BL
            // 
            this.Newgame_BL.BackColor = System.Drawing.Color.Gainsboro;
            this.Newgame_BL.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.Newgame_BL.Font = new System.Drawing.Font("Miramonte", 14.25F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Newgame_BL.Image = global::PhilipSandegren_Repition.Properties.Resources.button;
            this.Newgame_BL.Location = new System.Drawing.Point(301, 169);
            this.Newgame_BL.Name = "Newgame_BL";
            this.Newgame_BL.Size = new System.Drawing.Size(190, 56);
            this.Newgame_BL.TabIndex = 0;
            this.Newgame_BL.Text = "New Game";
            this.Newgame_BL.UseVisualStyleBackColor = false;
            this.Newgame_BL.Click += new System.EventHandler(this.Newgame_BL_Click);
            // 
            // Snake_BL
            // 
            this.Snake_BL.Enabled = false;
            this.Snake_BL.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Snake_BL.Image = global::PhilipSandegren_Repition.Properties.Resources.button;
            this.Snake_BL.Location = new System.Drawing.Point(52, 193);
            this.Snake_BL.Name = "Snake_BL";
            this.Snake_BL.Size = new System.Drawing.Size(190, 50);
            this.Snake_BL.TabIndex = 7;
            this.Snake_BL.Text = "Snake";
            this.Snake_BL.UseVisualStyleBackColor = true;
            this.Snake_BL.Visible = false;
            this.Snake_BL.Click += new System.EventHandler(this.Snake_BL_Click);
            // 
            // Spel
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.ClientSize = new System.Drawing.Size(844, 562);
            this.Controls.Add(this.Snake_BL);
            this.Controls.Add(this.Score_LBL);
            this.Controls.Add(this.Timer_LBL);
            this.Controls.Add(this.Mainpicture_PB);
            this.Controls.Add(this.Exit_BL);
            this.Controls.Add(this.Options_BL);
            this.Controls.Add(this.Newgame_BL);
            this.Cursor = System.Windows.Forms.Cursors.Cross;
            this.KeyPreview = true;
            this.MaximumSize = new System.Drawing.Size(860, 600);
            this.MinimumSize = new System.Drawing.Size(860, 600);
            this.Name = "Spel";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "UltraShooter";
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Spel_KeyDown);
            ((System.ComponentModel.ISupportInitialize)(this.Mainpicture_PB)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Newgame_BL;
        private System.Windows.Forms.Button Options_BL;
        private System.Windows.Forms.Button Exit_BL;
        public System.Windows.Forms.Timer Game_T;
        public System.Windows.Forms.Label Timer_LBL;
        public System.Windows.Forms.Label Score_LBL;
        private System.Windows.Forms.PictureBox Mainpicture_PB;
        private System.Windows.Forms.Button Snake_BL;


    }
}

