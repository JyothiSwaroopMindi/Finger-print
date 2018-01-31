namespace FingerPrint
{
    partial class FingerPrint
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
            this.enroll = new System.Windows.Forms.Button();
            this.match = new System.Windows.Forms.Button();
            this.delete = new System.Windows.Forms.Button();
            this.ide = new System.Windows.Forms.TextBox();
            this.display = new System.Windows.Forms.TextBox();
            this.start = new System.Windows.Forms.Button();
            this.stop = new System.Windows.Forms.Button();
            this.idd = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.name = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // enroll
            // 
            this.enroll.Location = new System.Drawing.Point(635, 30);
            this.enroll.Name = "enroll";
            this.enroll.Size = new System.Drawing.Size(75, 23);
            this.enroll.TabIndex = 0;
            this.enroll.Text = "ENROLL";
            this.enroll.UseVisualStyleBackColor = true;
            this.enroll.Click += new System.EventHandler(this.enroll_Click);
            // 
            // match
            // 
            this.match.Location = new System.Drawing.Point(635, 85);
            this.match.Name = "match";
            this.match.Size = new System.Drawing.Size(75, 23);
            this.match.TabIndex = 1;
            this.match.Text = "MATCH";
            this.match.UseVisualStyleBackColor = true;
            this.match.Click += new System.EventHandler(this.match_Click);
            // 
            // delete
            // 
            this.delete.Location = new System.Drawing.Point(635, 137);
            this.delete.Name = "delete";
            this.delete.Size = new System.Drawing.Size(75, 23);
            this.delete.TabIndex = 2;
            this.delete.Text = "DELETE";
            this.delete.UseVisualStyleBackColor = true;
            this.delete.Click += new System.EventHandler(this.delete_Click);
            // 
            // ide
            // 
            this.ide.Location = new System.Drawing.Point(510, 32);
            this.ide.Name = "ide";
            this.ide.Size = new System.Drawing.Size(50, 20);
            this.ide.TabIndex = 4;
            // 
            // display
            // 
            this.display.Location = new System.Drawing.Point(62, 32);
            this.display.Multiline = true;
            this.display.Name = "display";
            this.display.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal;
            this.display.Size = new System.Drawing.Size(417, 330);
            this.display.TabIndex = 5;
            // 
            // start
            // 
            this.start.Location = new System.Drawing.Point(624, 230);
            this.start.Name = "start";
            this.start.Size = new System.Drawing.Size(75, 23);
            this.start.TabIndex = 7;
            this.start.Text = "START";
            this.start.UseVisualStyleBackColor = true;
            this.start.Click += new System.EventHandler(this.start_Click);
            // 
            // stop
            // 
            this.stop.Location = new System.Drawing.Point(624, 280);
            this.stop.Name = "stop";
            this.stop.Size = new System.Drawing.Size(75, 23);
            this.stop.TabIndex = 8;
            this.stop.Text = "STOP";
            this.stop.UseVisualStyleBackColor = true;
            this.stop.Click += new System.EventHandler(this.stop_Click);
            // 
            // idd
            // 
            this.idd.Location = new System.Drawing.Point(513, 139);
            this.idd.Name = "idd";
            this.idd.Size = new System.Drawing.Size(50, 20);
            this.idd.TabIndex = 9;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(507, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(49, 13);
            this.label1.TabIndex = 10;
            this.label1.Text = "Enter ID ";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(510, 116);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(46, 13);
            this.label2.TabIndex = 11;
            this.label2.Text = "Enter ID";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(510, 230);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(76, 13);
            this.label3.TabIndex = 12;
            this.label3.Text = "START PORT";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(513, 280);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(69, 13);
            this.label4.TabIndex = 13;
            this.label4.Text = "STOP PORT";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(62, 13);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(58, 13);
            this.label5.TabIndex = 14;
            this.label5.Text = "MONITOR";
            // 
            // name
            // 
            this.name.Location = new System.Drawing.Point(510, 85);
            this.name.Name = "name";
            this.name.Size = new System.Drawing.Size(100, 20);
            this.name.TabIndex = 15;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(510, 69);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(63, 13);
            this.label6.TabIndex = 16;
            this.label6.Text = "Enter Name";
            // 
            // FingerPrint
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(739, 388);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.name);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.idd);
            this.Controls.Add(this.stop);
            this.Controls.Add(this.start);
            this.Controls.Add(this.display);
            this.Controls.Add(this.ide);
            this.Controls.Add(this.delete);
            this.Controls.Add(this.match);
            this.Controls.Add(this.enroll);
            this.Name = "FingerPrint";
            this.Text = "FingerPrint";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button enroll;
        private System.Windows.Forms.Button match;
        private System.Windows.Forms.Button delete;
        private System.Windows.Forms.TextBox ide;
        private System.Windows.Forms.TextBox display;
        private System.Windows.Forms.Button start;
        private System.Windows.Forms.Button stop;
        private System.Windows.Forms.TextBox idd;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox name;
        private System.Windows.Forms.Label label6;
    }
}

