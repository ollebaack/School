using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Snake
{
    public partial class Form1 : Form
    {
        private List<Circle> Snake = new List<Circle>();
        private Circle food = new Circle();

        public Form1()
        {
            InitializeComponent();

            //Set settings to default
            new Settings();

            //Set game Speed and start timer
            Gametimer.Interval = 1000 / Settings.Speed;
            Gametimer.Tick += UpdateScreen;
            Gametimer.Start();

            //Start New game 
            StartGame();
        }

        private void StartGame()
        {
            lblGameOver.Visible = false;

            //Set settings to default
            new Settings();

            //Create new player object
            Snake.Clear();
            Circle head = new Circle();
            head.X = 10;
            head.Y = 5;
            Snake.Add(head);

            lblscore.Text = Settings.Score.ToString();
            GenerateFood();

        }
        //Place random food game
        private void GenerateFood()
        {
            int maxXpos = pbCanvas.Size.Width / Settings.Width;
            int maxYpos = pbCanvas.Size.Height / Settings.Height;

            Random random = new Random();
            food = new Circle();
            food.X = random.Next(0, maxXpos);
            food.Y = random.Next(0, maxYpos);
        }

        private void UpdateScreen(object sender, EventArgs e)
        {
            //Check for Game Over
            if(Settings.GameOver == true)
            {
                //Check if Enter is pressed
                if(Input.Keypressed(Keys.Enter))
                {
                    StartGame();
                }
            }
            else
            {
                if (Input.Keypressed(Keys.Right) && Settings.direction != Direction.Left)
                    Settings.direction = Direction.Right;
                else if (Input.Keypressed(Keys.Left) && Settings.direction != Direction.Right)
                    Settings.direction = Direction.Left;
                else if (Input.Keypressed(Keys.Up) && Settings.direction != Direction.Down)
                    Settings.direction = Direction.Up;
                else if (Input.Keypressed(Keys.Down) && Settings.direction != Direction.Up)
                    Settings.direction = Direction.Down;

                MovePlayer();
            }

            pbCanvas.Invalidate();

        }

        private void pbCanvas_Paint(object sender, PaintEventArgs e)
        {
            Graphics canvas = e.Graphics;

            if (!Settings.GameOver)
            {
                //Draw snake
                Brush snakecolour;

                //Draw snake
                for(int i = 0; i< Snake.Count; i++ )
                {

                    if (i == 0)
                        snakecolour = Brushes.Black;    //Draw head
                    else
                        snakecolour = Brushes.Green;    //Rest of body

                    //Draw snake
                    canvas.FillEllipse(snakecolour,
                        new Rectangle(Snake[i].X = Settings.Width,
                                      Snake[i].Y = Settings.Height,
                                      Settings.Width, Settings.Height));

                    //Draw Food
                    canvas.FillEllipse(Brushes.Red,
                        new Rectangle(food.X = Settings.Width,
                        food.Y = Settings.Height, Settings.Width, Settings.Height));
                }

            }
            else
            {
                string gameOver = "Game over \nYour final score is: " + Settings.Score + "\nPress Enter to try again";
                lblGameOver.Text = gameOver;
                lblGameOver.Visible = true;
            }
        }

        private void MovePlayer()
        {
            for(int i = Snake.Count -1; i >= 0; i--)
            {
                //Move head
                if (i == 0)
                {
                    switch (Settings.direction)
                    {
                        case Direction.Right:
                            Snake[i].X++;
                            break;
                        case Direction.Left:
                            Snake[i].X--;
                            break;
                        case Direction.Up:
                            Snake[i].Y--;
                            break;
                        case Direction.Down:
                            Snake[i].Y++;
                            break;

                    }
                    //Get maximum X and Y Pos
                    int maxXpos = pbCanvas.Size.Width / Settings.Width;
                    int maxYpos = pbCanvas.Size.Height / Settings.Height;

                    //Detect Collision with game borders.
                    if (Snake[i].X < 0 || Snake[i].Y < 0
                        || Snake[i].X >= maxXpos || Snake[i].Y >= maxYpos)
                    {
                        //Die();
                    }
                    //Detect collision with body
                    for (int j = 1; j < Snake.Count; j++)
                    {
                        if(Snake[i].X == Snake[j].X &&
                            Snake[i].Y == Snake[j].Y )
                        {
                           // Die();
                        }

                    }

                    //Detect Collision with food piece
                    if(Snake[0].X == food.X && Snake[0].Y == food.Y)
                    {
                        //Eat();
                    }

                }
                else
                {
                    //Move body
                    Snake[i].X = Snake[i - 1].X;
                    Snake[i].Y = Snake[i - 1].Y;
                }
            }

        }

        private void Eat()
        {
            Circle food = new Circle();
            food.X = Snake[Snake.Count - 1].X;
            food.Y = Snake[Snake.Count - 1].Y;

            Snake.Add(food);


            //update score
            Settings.Score += Settings.Points;
            lblscore.Text = Settings.Score.ToString();
        }

        private void Die()
        {
            Settings.GameOver = true;
        }
     
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            Input.ChangeState(e.KeyCode, true);
        }

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            Input.ChangeState(e.KeyCode, false);
        }
    }
}
