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
	
namespace MyGame
{
    public partial class Form2 : Form
    {

        bool right, left;
        bool jump;
        int G = 20;
        int Force;
        private SoundPlayer _soundPlayer;
        private List<PictureBox> List = new List<PictureBox>();
        private List<PictureBox> Bomb = new List<PictureBox>();
        private List<PictureBox> WorldObjects = new List<PictureBox>();
        private PictureBox pictureBox1;
        private PictureBox pictureBox2;
        private PictureBox pictureBox3;
        private PictureBox pictureBox4;
        private PictureBox pictureBox5;
        private PictureBox pictureBox6;
        private PictureBox pictureBox7;
        private PictureBox pictureBox8;
        private PictureBox Player1;
        private PictureBox pictureBox9;
        private PictureBox pictureBox10;
        private PictureBox pictureBox11;
        private PictureBox pictureBox12;
        private PictureBox pictureBox13;
        private PictureBox pictureBox14;
        private PictureBox pictureBox15;
        private PictureBox pictureBox16;
        private PictureBox pictureBox17;
        private PictureBox pictureBox18;
        private Panel WorldFrame2;
        private Timer timer1;
        private IContainer components;
        string DebugLog = "STARTED: " + DateTime.Now + "\n";

        public Form2()
        {
            InitializeComponent();
            _soundPlayer = new SoundPlayer("Jump.wav");

            Player1.Top = WorldFrame2.Height - Player1.Height; //Sets the pictureBox start position
            List.Add(pictureBox1);
            List.Add(pictureBox2);
            List.Add(pictureBox3);
            List.Add(pictureBox4);
            List.Add(pictureBox5);
            List.Add(pictureBox6);
            List.Add(pictureBox7);
            List.Add(pictureBox8);
            List.Add(Player1);
            List.Add(pictureBox10);
            List.Add(pictureBox11);
            List.Add(pictureBox12);
            List.Add(pictureBox13);
            List.Add(pictureBox14);
            List.Add(pictureBox15);
            List.Add(pictureBox16);
            List.Add(pictureBox17);
            List.Add(pictureBox18);

            WorldObjects.Add(pictureBox1);
            WorldObjects.Add(pictureBox2);
            WorldObjects.Add(pictureBox3);
            WorldObjects.Add(pictureBox4);
            WorldObjects.Add(pictureBox5);
            WorldObjects.Add(pictureBox6);
            WorldObjects.Add(pictureBox7);
            WorldObjects.Add(pictureBox8);
            WorldObjects.Add(Player1);
            WorldObjects.Add(pictureBox10);
            WorldObjects.Add(pictureBox11);
            WorldObjects.Add(pictureBox12);
            WorldObjects.Add(pictureBox13);
            WorldObjects.Add(pictureBox14);
            WorldObjects.Add(pictureBox15);
            WorldObjects.Add(pictureBox16);
            WorldObjects.Add(pictureBox17);
            WorldObjects.Add(pictureBox18);

        }
        public new void Dispose()
        {
            // Dispose of unmanaged resources.
            Dispose(true);
            // Suppress finalization.
            GC.SuppressFinalize(this);
        }
        
public void Player1Spawn()
        {
            Player1.Top = WorldFrame2.Height - Player1.Height;
        }
        public Boolean OutsideWorldFrame2(PictureBox tar)
        {
               if (tar.Location.X< 0) //Is it outside of the left side?
                   return true;
               if (tar.Location.X > WorldFrame2.Width)  //... right side?
                   return true;
               if (tar.Location.Y + tar.Height > WorldFrame2.Height - 3)
                   return true;                        //Or above the WorldFrame2?
              foreach (PictureBox Obj in Bomb)
               {
                   if (Obj != null)
                   {   //Or, intersecting with any world object
                       if (tar.Bounds.IntersectsWith(Obj.Bounds))
                           return true;
                  }
               }
               return false;
           }
        public Boolean InAirNoCollision(PictureBox tar)
        {   //Checks if the target Picturebox is Outside of the 
            if (!OutsideWorldFrame2(tar))
            {
                foreach (PictureBox Obj in WorldObjects)
                {   //Or if it's not colliding with anything
                    if (!tar.Bounds.IntersectsWith(Obj.Bounds))
                    {
                        if (tar.Location.Y < WorldFrame2.Width)
                        {   //And it's not under ground for some reason
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {


            if (right == true)
                Player1.Left += 3;
            if (left == true)
                Player1.Left -= 3;

            if (jump == true)
            {
                //Falling (if the Player1 has jumped before)
                Player1.Top -= Force;
                Force -= 1;
            }

            foreach (var pictureBox in List)
            {
                if (Player1.Right > pictureBox.Left && Player1.Left < pictureBox.Right - Player1.Width && Player1.Bottom < pictureBox.Bottom && Player1.Bottom > pictureBox.Top)
                {
                    right = false;
                }

                if (Player1.Left < pictureBox.Right && Player1.Right > pictureBox.Left + Player1.Width && Player1.Bottom < pictureBox.Bottom && Player1.Bottom > pictureBox.Top)
                {
                    left = false;
                }

            }
            if (Player1.Top + Player1.Height >= WorldFrame2.Height)
            {
                Player1.Top = WorldFrame2.Height - Player1.Height; //Stop failling at bottom
                if (jump == true)
                    Player1.Image = Image.FromFile("Stick-Figure stående 2.jpg");
                jump = false;
            }
            else
            {
                Player1.Top += 5; //Falling
            }


            foreach (var pictureBox in List)
            {
                //Top Collision

                if (Player1.Left + Player1.Width > pictureBox.Left && Player1.Left + Player1.Width < pictureBox.Left + pictureBox.Width + Player1.Width && Player1.Top + Player1.Height >= pictureBox.Top && Player1.Top < pictureBox.Top)
                {

                    Player1.Top = pictureBox.Location.Y - Player1.Height;
                    Force = 0;
                    if (jump == true)
                        Player1.Image = Image.FromFile("Stick-Figure stående 2.jpg");

                    jump = false;
                }
                //Head Collision
                if (Player1.Left + Player1.Width > pictureBox.Left && Player1.Left + Player1.Width < pictureBox.Left + pictureBox.Width + Player1.Width && Player1.Top + Player1.Height >= pictureBox.Bottom && Player1.Top < pictureBox.Bottom)
                {
                    Force = -1;

                }










            }
        }
        private void Form2_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Right)
            { 
                right = true;
                Player1.Image = Image.FromFile("Stick-Figure Right.jpg");
            }
            if (e.KeyCode == Keys.Left)
            {
                left = true;
                Player1.Image = Image.FromFile("Stick-Figure Left.jpg");
            }
            if (e.KeyCode == Keys.Escape)
                this.Close(); //Escape -> Exit

            if (jump != true)
            {
                if (e.KeyCode == Keys.Up)
                {
                    jump = true;
                    Force = G;
                    Player1.Image = Image.FromFile("Stick-Figure Jump.jpg");
                    _soundPlayer.Play();

                }

            }
        }

  
        private void Form2_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Right)
                right = false;
            if (e.KeyCode == Keys.Left)
                left = false;

        }
        public void Reset()
        {   //Resets everything
            Player1Spawn();
            //label_Dead.Visible = false;
            int x = 0;
            foreach (PictureBox rocket in Bomb)
            {
                if (Bomb != null)
                {   //Removes all the bombs
                    rocket.Dispose();
                    Bomb[x] = null; ;
                }
                x++;
            }
        }

        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.Player1 = new System.Windows.Forms.PictureBox();
            this.pictureBox8 = new System.Windows.Forms.PictureBox();
            this.pictureBox7 = new System.Windows.Forms.PictureBox();
            this.pictureBox6 = new System.Windows.Forms.PictureBox();
            this.pictureBox5 = new System.Windows.Forms.PictureBox();
            this.pictureBox4 = new System.Windows.Forms.PictureBox();
            this.pictureBox3 = new System.Windows.Forms.PictureBox();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.pictureBox9 = new System.Windows.Forms.PictureBox();
            this.pictureBox10 = new System.Windows.Forms.PictureBox();
            this.pictureBox11 = new System.Windows.Forms.PictureBox();
            this.pictureBox12 = new System.Windows.Forms.PictureBox();
            this.pictureBox13 = new System.Windows.Forms.PictureBox();
            this.pictureBox14 = new System.Windows.Forms.PictureBox();
            this.pictureBox15 = new System.Windows.Forms.PictureBox();
            this.pictureBox16 = new System.Windows.Forms.PictureBox();
            this.pictureBox17 = new System.Windows.Forms.PictureBox();
            this.pictureBox18 = new System.Windows.Forms.PictureBox();
            this.WorldFrame2 = new System.Windows.Forms.Panel();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.Player1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox8)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox7)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox6)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox5)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox9)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox10)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox11)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox12)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox13)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox14)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox15)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox16)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox17)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox18)).BeginInit();
            this.WorldFrame2.SuspendLayout();
            this.SuspendLayout();
            // 
            // Player1
            // 
            this.Player1.BackColor = System.Drawing.Color.Transparent;
            this.Player1.Image = global::MyGame.Properties.Resources.Stick_Figure_Stående_2;
            this.Player1.Location = new System.Drawing.Point(85, 1388);
            this.Player1.Name = "Player1";
            this.Player1.Size = new System.Drawing.Size(50, 80);
            this.Player1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.Player1.TabIndex = 8;
            this.Player1.TabStop = false;
            // 
            // pictureBox8
            // 
            this.pictureBox8.BackColor = System.Drawing.Color.DimGray;
            this.pictureBox8.Location = new System.Drawing.Point(801, 1093);
            this.pictureBox8.Name = "pictureBox8";
            this.pictureBox8.Size = new System.Drawing.Size(90, 34);
            this.pictureBox8.TabIndex = 7;
            this.pictureBox8.TabStop = false;
            // 
            // pictureBox7
            // 
            this.pictureBox7.BackColor = System.Drawing.Color.DimGray;
            this.pictureBox7.Location = new System.Drawing.Point(611, 1093);
            this.pictureBox7.Name = "pictureBox7";
            this.pictureBox7.Size = new System.Drawing.Size(90, 34);
            this.pictureBox7.TabIndex = 6;
            this.pictureBox7.TabStop = false;
            // 
            // pictureBox6
            // 
            this.pictureBox6.BackColor = System.Drawing.Color.DimGray;
            this.pictureBox6.Location = new System.Drawing.Point(1055, 1035);
            this.pictureBox6.Name = "pictureBox6";
            this.pictureBox6.Size = new System.Drawing.Size(90, 34);
            this.pictureBox6.TabIndex = 5;
            this.pictureBox6.TabStop = false;
            // 
            // pictureBox5
            // 
            this.pictureBox5.BackColor = System.Drawing.Color.DimGray;
            this.pictureBox5.Location = new System.Drawing.Point(243, 1063);
            this.pictureBox5.Name = "pictureBox5";
            this.pictureBox5.Size = new System.Drawing.Size(90, 34);
            this.pictureBox5.TabIndex = 4;
            this.pictureBox5.TabStop = false;
            this.pictureBox5.Click += new System.EventHandler(this.pictureBox5_Click);
            // 
            // pictureBox4
            // 
            this.pictureBox4.BackColor = System.Drawing.Color.DimGray;
            this.pictureBox4.Location = new System.Drawing.Point(407, 1063);
            this.pictureBox4.Name = "pictureBox4";
            this.pictureBox4.Size = new System.Drawing.Size(90, 34);
            this.pictureBox4.TabIndex = 3;
            this.pictureBox4.TabStop = false;
            // 
            // pictureBox3
            // 
            this.pictureBox3.BackColor = System.Drawing.Color.DimGray;
            this.pictureBox3.Location = new System.Drawing.Point(199, 953);
            this.pictureBox3.Name = "pictureBox3";
            this.pictureBox3.Size = new System.Drawing.Size(90, 34);
            this.pictureBox3.TabIndex = 2;
            this.pictureBox3.TabStop = false;
            // 
            // pictureBox2
            // 
            this.pictureBox2.BackColor = System.Drawing.Color.DimGray;
            this.pictureBox2.Location = new System.Drawing.Point(525, 895);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(90, 34);
            this.pictureBox2.TabIndex = 1;
            this.pictureBox2.TabStop = false;
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackColor = System.Drawing.Color.DimGray;
            this.pictureBox1.Location = new System.Drawing.Point(442, 496);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(90, 34);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // pictureBox9
            // 
            this.pictureBox9.BackColor = System.Drawing.Color.DimGray;
            this.pictureBox9.Location = new System.Drawing.Point(1105, 953);
            this.pictureBox9.Name = "pictureBox9";
            this.pictureBox9.Size = new System.Drawing.Size(90, 34);
            this.pictureBox9.TabIndex = 9;
            this.pictureBox9.TabStop = false;
            // 
            // pictureBox10
            // 
            this.pictureBox10.BackColor = System.Drawing.Color.DimGray;
            this.pictureBox10.Location = new System.Drawing.Point(1255, 629);
            this.pictureBox10.Name = "pictureBox10";
            this.pictureBox10.Size = new System.Drawing.Size(90, 34);
            this.pictureBox10.TabIndex = 10;
            this.pictureBox10.TabStop = false;
            // 
            // pictureBox11
            // 
            this.pictureBox11.BackColor = System.Drawing.Color.DimGray;
            this.pictureBox11.Location = new System.Drawing.Point(1055, 615);
            this.pictureBox11.Name = "pictureBox11";
            this.pictureBox11.Size = new System.Drawing.Size(90, 34);
            this.pictureBox11.TabIndex = 11;
            this.pictureBox11.TabStop = false;
            // 
            // pictureBox12
            // 
            this.pictureBox12.BackColor = System.Drawing.Color.DimGray;
            this.pictureBox12.Location = new System.Drawing.Point(481, 663);
            this.pictureBox12.Name = "pictureBox12";
            this.pictureBox12.Size = new System.Drawing.Size(90, 34);
            this.pictureBox12.TabIndex = 12;
            this.pictureBox12.TabStop = false;
            // 
            // pictureBox13
            // 
            this.pictureBox13.BackColor = System.Drawing.Color.DimGray;
            this.pictureBox13.Location = new System.Drawing.Point(715, 537);
            this.pictureBox13.Name = "pictureBox13";
            this.pictureBox13.Size = new System.Drawing.Size(90, 34);
            this.pictureBox13.TabIndex = 13;
            this.pictureBox13.TabStop = false;
            // 
            // pictureBox14
            // 
            this.pictureBox14.BackColor = System.Drawing.Color.DimGray;
            this.pictureBox14.Location = new System.Drawing.Point(693, 663);
            this.pictureBox14.Name = "pictureBox14";
            this.pictureBox14.Size = new System.Drawing.Size(90, 34);
            this.pictureBox14.TabIndex = 14;
            this.pictureBox14.TabStop = false;
            // 
            // pictureBox15
            // 
            this.pictureBox15.BackColor = System.Drawing.Color.DimGray;
            this.pictureBox15.Location = new System.Drawing.Point(647, 807);
            this.pictureBox15.Name = "pictureBox15";
            this.pictureBox15.Size = new System.Drawing.Size(90, 34);
            this.pictureBox15.TabIndex = 15;
            this.pictureBox15.TabStop = false;
            // 
            // pictureBox16
            // 
            this.pictureBox16.BackColor = System.Drawing.Color.DimGray;
            this.pictureBox16.Location = new System.Drawing.Point(1245, 797);
            this.pictureBox16.Name = "pictureBox16";
            this.pictureBox16.Size = new System.Drawing.Size(90, 34);
            this.pictureBox16.TabIndex = 16;
            this.pictureBox16.TabStop = false;
            // 
            // pictureBox17
            // 
            this.pictureBox17.BackColor = System.Drawing.Color.DimGray;
            this.pictureBox17.Location = new System.Drawing.Point(1037, 767);
            this.pictureBox17.Name = "pictureBox17";
            this.pictureBox17.Size = new System.Drawing.Size(90, 34);
            this.pictureBox17.TabIndex = 17;
            this.pictureBox17.TabStop = false;
            // 
            // pictureBox18
            // 
            this.pictureBox18.BackColor = System.Drawing.Color.DimGray;
            this.pictureBox18.Location = new System.Drawing.Point(959, 903);
            this.pictureBox18.Name = "pictureBox18";
            this.pictureBox18.Size = new System.Drawing.Size(90, 34);
            this.pictureBox18.TabIndex = 18;
            this.pictureBox18.TabStop = false;
            // 
            // WorldFrame2
            // 
            this.WorldFrame2.BackColor = System.Drawing.Color.White;
            this.WorldFrame2.Controls.Add(this.Player1);
            this.WorldFrame2.Controls.Add(this.pictureBox8);
            this.WorldFrame2.Controls.Add(this.pictureBox7);
            this.WorldFrame2.Controls.Add(this.pictureBox6);
            this.WorldFrame2.Controls.Add(this.pictureBox5);
            this.WorldFrame2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.WorldFrame2.Location = new System.Drawing.Point(0, 0);
            this.WorldFrame2.Name = "WorldFrame2";
            this.WorldFrame2.Size = new System.Drawing.Size(3180, 1724);
            this.WorldFrame2.TabIndex = 0;
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Interval = 1;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(16F, 31F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(3180, 1724);
            this.Controls.Add(this.pictureBox18);
            this.Controls.Add(this.pictureBox17);
            this.Controls.Add(this.pictureBox16);
            this.Controls.Add(this.pictureBox15);
            this.Controls.Add(this.pictureBox14);
            this.Controls.Add(this.pictureBox13);
            this.Controls.Add(this.pictureBox12);
            this.Controls.Add(this.pictureBox11);
            this.Controls.Add(this.pictureBox10);
            this.Controls.Add(this.pictureBox9);
            this.Controls.Add(this.pictureBox4);
            this.Controls.Add(this.pictureBox3);
            this.Controls.Add(this.pictureBox2);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.WorldFrame2);
            this.Name = "Form2";
            this.Text = "MyGame";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.Load += new System.EventHandler(this.Form2_Load_1);
            ((System.ComponentModel.ISupportInitialize)(this.Player1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox8)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox7)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox6)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox5)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox9)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox10)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox11)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox12)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox13)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox14)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox15)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox16)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox17)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox18)).EndInit();
            this.WorldFrame2.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        private void pictureBox12_Click(object sender, EventArgs e)
        {

        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void Form2_Load_1(object sender, EventArgs e)
        {

        }

        private void pictureBox5_Click(object sender, EventArgs e)
        {

        }




        //public void Reset()
        //{
        //    Player1Spawn();

        //}


        public void Dead()
        {


        }
    }
}
