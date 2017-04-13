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
    public partial class Form1 : Form
    {
        Form2 form2 = null;
        bool right, left;
        bool jump;
        int G = 20;
        int Force;
        private SoundPlayer _soundplayer;
        private List<PictureBox> List = new List<PictureBox>();
        private List<PictureBox> Bomb = new List<PictureBox>();
        private List<PictureBox> WorldObjects = new List<PictureBox>();
        string DebugLog = "STARTED: " + DateTime.Now + "\n";

        public Form1()
        {
            InitializeComponent();
            form2 = new Form2();
            _soundplayer = new SoundPlayer("Jump.wav");

            Player.Top = WorldFrame.Height - Player.Height; //Sets the block start position
            List.Add(Block1);
            List.Add(Block2);
            List.Add(Block3);
            List.Add(Block4);
            List.Add(Block5);
            List.Add(Block6);
            List.Add(Block7);
            List.Add(Block8);
            List.Add(Block9);
            List.Add(Block10);
            List.Add(Block11);
            Bomb.Add(Rocket1);
            Bomb.Add(Rocket2);
            Bomb.Add(Rocket3);
            Bomb.Add(Rocket4);
            WorldObjects.Add(Block1);
            WorldObjects.Add(Block2);
            WorldObjects.Add(Block3);
            WorldObjects.Add(Block4);
            WorldObjects.Add(Block5);
            WorldObjects.Add(Block6);
            WorldObjects.Add(Block7);
            WorldObjects.Add(Block8);
            WorldObjects.Add(Block9);
            WorldObjects.Add(Block10);
            WorldObjects.Add(Block11);
            WorldObjects.Add(Rocket1);
            WorldObjects.Add(Rocket2);
            WorldObjects.Add(Rocket3);
            WorldObjects.Add(Rocket4);
        }
        public new void Dispose()
        {
            // Dispose of unmanaged resources.
            Dispose(true);
            // Suppress finalization.
            GC.SuppressFinalize(this);
        }
        
public void PlayerSpawn()
        {
            Player.Top = WorldFrame.Height - Player.Height;
        }
public void RocketSpawn(PictureBox tar)
        {
            tar.Top = WorldFrame.Height - tar.Height;
        }        
        public Boolean OutsideWorldFrame(PictureBox tar)
        {
               if (tar.Location.X< 0) //Is it outside of the left side?
                   return true;
               if (tar.Location.X > WorldFrame.Width)  //... right side?
                   return true;
               if (tar.Location.Y + tar.Height > WorldFrame.Height - 3)
                   return true;                        //Or above the WorldFrame?
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
            if (!OutsideWorldFrame(tar))
            {
                foreach (PictureBox Obj in WorldObjects)
                {   //Or if it's not colliding with anything
                    if (!tar.Bounds.IntersectsWith(Obj.Bounds))
                    {
                        if (tar.Location.Y < WorldFrame.Width)
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
                Player.Left += 3;
            if (left == true)
                Player.Left -= 3;

            if (jump == true)
            {
                //Falling (if the player has jumped before)
                Player.Top -= Force;
                Force -= 1;
            }

            foreach (var block in List)
            {
                if (Player.Right > block.Left && Player.Left < block.Right - Player.Width && Player.Bottom < block.Bottom && Player.Bottom > block.Top)
                {
                    right = false;
                }

                if (Player.Left < block.Right && Player.Right > block.Left + Player.Width && Player.Bottom < block.Bottom && Player.Bottom > block.Top)
                {
                    left = false;
                }

            }
            if (Player.Top + Player.Height >= WorldFrame.Height)
            {
                Player.Top = WorldFrame.Height - Player.Height; //Stop failling at bottom
                if (jump == true)
                    Player.Image = Image.FromFile("Stick-Figure stående 2.jpg");
                jump = false;
            }
            else
            {
                Player.Top += 5; //Falling
            }


            foreach (var block in List)
            {
                //Top Collision

                if (Player.Left + Player.Width > block.Left && Player.Left + Player.Width < block.Left + block.Width + Player.Width && Player.Top + Player.Height >= block.Top && Player.Top < block.Top)
                {

                    Player.Top = block.Location.Y - Player.Height;
                    Force = 0;
                    if (jump == true)
                        Player.Image = Image.FromFile("Stick-Figure stående 2.jpg");

                    jump = false;
                }
                //Head Collision
                if (Player.Left + Player.Width > block.Left && Player.Left + Player.Width < block.Left + block.Width + Player.Width && Player.Top + Player.Height >= block.Bottom && Player.Top < block.Bottom)
                {
                    Force = -1;

                }



                foreach (var rocket in Bomb)
                {

                    rocket.Left -= 1;
                    if (OutsideWorldFrame(rocket))
                        RocketSpawn(rocket);



                }
                //Goal
                if (Player.Left + Player.Width > Goal.Left && Player.Left + Player.Width < Goal.Left + Goal.Width + Player.Width && Player.Top + Player.Height >= Goal.Top && Player.Top < Goal.Top)
                {

                    Player.Top = Goal.Location.Y - Player.Height;
                    Force = 0;
                    PlayerSpawn();
                    this.Hide();
                    form2.Show();
                    
                    if (jump == true)
                        Player.Image = Image.FromFile("Stick-Figure stående 2.jpg");

                    jump = false;
                }
                //Head Collision
                if (Player.Left + Player.Width > Goal.Left && Player.Left + Player.Width < Goal.Left + Goal.Width + Player.Width && Player.Top + Player.Height >= Goal.Bottom && Player.Top < Goal.Bottom)
                {
                    Force = -1;
                    
                    this.Hide();
                    form2.Show();
                   
                }






            }
        }
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Right)
            { 
                right = true;
                Player.Image = Image.FromFile("Stick-Figure Right.jpg");
            }
            if (e.KeyCode == Keys.Left)
            {
                left = true;
                Player.Image = Image.FromFile("Stick-Figure Left.jpg");
            }
            if (e.KeyCode == Keys.Escape)
                this.Close(); //Escape -> Exit

            if (jump != true)
            {
                if (e.KeyCode == Keys.Up)
                {
                    jump = true;
                    Force = G;
                    Player.Image = Image.FromFile("Stick-Figure Jump.jpg");
                    _soundplayer.Play();

                }

            }
        }

  
        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Right)
                right = false;
            if (e.KeyCode == Keys.Left)
                left = false;

        }
        public void Reset()
        {   //Resets everything
            PlayerSpawn();
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


        //public void Reset()
        //{
        //    PlayerSpawn();

        //}


        public void Dead()
        {


        }
    }
}
