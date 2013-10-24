namespace PhilipSandegren_RoligtSpel
{
    partial class Form1
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
            this.skriv_BL = new System.Windows.Forms.Button();
            this.input_TBX = new System.Windows.Forms.TextBox();
            this.output_LBL = new System.Windows.Forms.Label();
            this.monthCalendar1 = new System.Windows.Forms.MonthCalendar();
            this.SuspendLayout();
            // 
            // skriv_BL
            // 
            this.skriv_BL.Location = new System.Drawing.Point(103, 48);
            this.skriv_BL.Name = "skriv_BL";
            this.skriv_BL.Size = new System.Drawing.Size(75, 23);
            this.skriv_BL.TabIndex = 0;
            this.skriv_BL.Text = "Tryck mig";
            this.skriv_BL.UseVisualStyleBackColor = true;
            this.skriv_BL.Click += new System.EventHandler(this.skriv_BL_Click);
            // 
            // input_TBX
            // 
            this.input_TBX.Location = new System.Drawing.Point(90, 12);
            this.input_TBX.Name = "input_TBX";
            this.input_TBX.Size = new System.Drawing.Size(100, 20);
            this.input_TBX.TabIndex = 1;
            // 
            // output_LBL
            // 
            this.output_LBL.AutoSize = true;
            this.output_LBL.Location = new System.Drawing.Point(122, 94);
            this.output_LBL.Name = "output_LBL";
            this.output_LBL.Size = new System.Drawing.Size(52, 13);
            this.output_LBL.TabIndex = 2;
            this.output_LBL.Text = "Utskriften";
            // 
            // monthCalendar1
            // 
            this.monthCalendar1.Location = new System.Drawing.Point(216, 12);
            this.monthCalendar1.Name = "monthCalendar1";
            this.monthCalendar1.TabIndex = 3;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(443, 194);
            this.Controls.Add(this.monthCalendar1);
            this.Controls.Add(this.output_LBL);
            this.Controls.Add(this.input_TBX);
            this.Controls.Add(this.skriv_BL);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button skriv_BL;
        private System.Windows.Forms.TextBox input_TBX;
        private System.Windows.Forms.Label output_LBL;
        private System.Windows.Forms.MonthCalendar monthCalendar1;
    }
}

