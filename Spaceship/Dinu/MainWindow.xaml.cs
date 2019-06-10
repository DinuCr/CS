using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.Windows.Threading;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Collections;
using System.Speech.Synthesis;

namespace Dinu
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    /// 
    public partial class MainWindow : Window
    {
        private Image Bonus = new Image();
        List<int> enemies_type = new List<int>();
        List<Image> enemy_bullets = new List<Image>();
        List<Image> bullets = new List<Image>();
        List<Image> enemies = new List<Image>();
        DateTime last_bullet = DateTime.Now;
        private Image ship = new Image();
        Boolean ok = false;
        private int ship_height = 810;
        private int ship_position = 700;
        private int enemy_shooters = 0;

        DateTime start_time = new DateTime();

        DispatcherTimer enemy_bullet_time = new DispatcherTimer();
        DispatcherTimer new_ship_time = new DispatcherTimer();
        DispatcherTimer move_shoot_time = new DispatcherTimer();
        DispatcherTimer bullet_time = new DispatcherTimer();

        int game_enemies = 0;
        int last_high_score = 0;
        int another = 0;

        int exists_bonus = 0;
        int shoot_upgrade = 0;

        int curr_score;
        int total_bullets;
        int killed_1;
        int killed_2;

        public struct save_data
        {
            public int high_score;
            public int total_bullets;
            public int killed_1;
            public int killed_2;
            public int games_played;
        };

        public void save_game()
        {
            Hashtable to_save = new Hashtable();
            save_data stats = new save_data();

            stats = load_game();
            stats.high_score = System.Math.Max(stats.high_score, curr_score);
            stats.total_bullets += total_bullets;
            stats.killed_1 += killed_1;
            stats.killed_2 += killed_2;
            ++stats.games_played;

            to_save.Add("killed_1", stats.killed_1);
            to_save.Add("killed_2", stats.killed_2);
            to_save.Add("total_bullets", stats.total_bullets);
            to_save.Add("high_score", stats.high_score);
            to_save.Add("games_played", stats.games_played);

            FileStream fs = new FileStream("saved_data.dat", FileMode.Create);
            BinaryFormatter formatter = new BinaryFormatter();

            formatter.Serialize(fs, to_save);
            fs.Close();
        }

        public save_data load_game()
        {
            Hashtable loading = null;

            save_data ans = new save_data();

            if (File.Exists("saved_data.dat"))
            {
                FileStream fs = new FileStream("saved_data.dat", FileMode.Open);
                BinaryFormatter formatter = new BinaryFormatter();
                loading = (Hashtable)formatter.Deserialize(fs);

                ans.high_score = (int)loading["high_score"];
                ans.killed_1 = (int)loading["killed_1"];
                ans.killed_2 = (int)loading["killed_2"];
                ans.total_bullets = (int)loading["total_bullets"];
                ans.games_played = (int)loading["games_played"];

                fs.Close();
            }
            else
            {
                ans.killed_1 = 0;
                ans.killed_2 = 0;
                ans.high_score = 0;
                ans.total_bullets = 0;
                ans.games_played = 0;
            }
            return ans;
        }

        public MainWindow()
        {
            InitializeComponent();
            KeyDown += exit;
            bullet_time.Tick += Update_bullet;
            move_shoot_time.Tick += move;
            move_shoot_time.Tick += shoot;
            new_ship_time.Tick += add_enemy;
            new_ship_time.Tick += enemy_shoot;
            enemy_bullet_time.Tick += update_enemy_bullet;
            enemy_bullet_time.Tick += update_enemy_bullet;
        }

        private async void move(object sender, EventArgs e)
        {
            if (Keyboard.IsKeyDown(Key.Left))
            {
                for (int i = 0; i <= 6; ++i)
                {
                    await Task.Delay(1);
                    if (ship_position > 5)
                    {
                        ship_position -= 1;
                        Canvas.SetLeft(ship, ship_position);
                    }
                }
            }
            if (Keyboard.IsKeyDown(Key.Right))
            {
                for (int i = 0; i <= 6; ++i)
                {
                    await Task.Delay(1);
                    if (ship_position <= 1440)
                    {
                        ship_position += 1;
                        Canvas.SetLeft(ship, ship_position);
                    }
                }
            }

            if (Keyboard.IsKeyDown(Key.Up))
            {
                for (int i = 0; i <= 2; ++i)
                {
                    await Task.Delay(1);
                    if (ship_height >= 100)
                    {
                        ship_height -= 1;
                        Canvas.SetTop(ship, ship_height);
                    }
                }
            }
            if (Keyboard.IsKeyDown(Key.Down))
            {
                for (int i = 0; i <= 2; ++i)
                {
                    await Task.Delay(1);
                    if (ship_height <= 810)
                    {
                        ship_height += 1;
                        Canvas.SetTop(ship, ship_height);
                    }
                }
            }
        }

        private void Update_bullet(object sender, EventArgs e)
        {
            Update_enemies();
            Update_enemies();
            Update_enemies();
            Canvas playground = playground_canvas;
            int del = -1;
            for (int i = 0; i < bullets.Count; ++i)
            {
                double pos;

                pos = Canvas.GetTop(bullets[i]);

                if (pos <= 5)
                    del = i;

                Canvas.SetTop(bullets[i], pos - 12);

                Rect curr = new Rect(new Point(Canvas.GetLeft(bullets[i]), Canvas.GetTop(bullets[i])), new Point(Canvas.GetLeft(bullets[i]) + 8, Canvas.GetTop(bullets[i]) + 20));

                for (int j = 0; j < enemies.Count; ++j)
                {
                    Rect curr2 = new Rect(new Point(Canvas.GetLeft(enemies[j]), Canvas.GetTop(enemies[j])), new Point(Canvas.GetLeft(enemies[j]) + 45, Canvas.GetTop(enemies[j]) + 80));
                    if (curr.IntersectsWith(curr2))
                    {
                        playground.Children.Remove(bullets[i]);
                        if (enemies_type[j] == 1)
                        {
                            ++killed_1;
                            ++curr_score;
                        }
                        else
                        {
                            curr_score += 2;
                            ++killed_2;
                        }

                        MediaPlayer a = new MediaPlayer();
                        a.Open(new Uri(AppDomain.CurrentDomain.BaseDirectory + "/blast.wav"));
                        a.Play();
                        Task.Delay(250).ContinueWith(_ =>
                        { a.Stop(); });

                        if ((killed_1 + killed_2) % 40 == 0 && (killed_1 + killed_2) > 0 && exists_bonus == 0)
                        {
                            exists_bonus = 1;
                            playground.Children.Add(Bonus);
                            Canvas.SetTop(Bonus, pos - 30);
                            Canvas.SetLeft(Bonus, Canvas.GetLeft(bullets[i]));
                        }

                        enemies_type.RemoveAt(j);
                        bullets.RemoveAt(i);
                        --i;
                        playground.Children.Remove(enemies[j]);
                        enemies.RemoveAt(j);
                        TextBlock t = score_text;
                        t.Text = "Score : " + curr_score.ToString();
                        if (curr_score > last_high_score && another == 0)
                        {
                            another = 1;
                            SpeechSynthesizer voice = new SpeechSynthesizer();
                            voice.SpeakAsync("good job, you beat the last high score");
                        }
                        break;
                    }
                }
            }
            for (int i = 0; i <= del; ++i)
            {
                playground.Children.Remove(bullets[i]);
            }
            if (del >= 0)
                bullets.RemoveRange(0, del);
        }

        private void Update_enemies()
        {
            Update_bonus();
            Canvas playground = playground_canvas;

            int del = -1;
            for (int i = 0; i < enemies.Count; ++i)
            {
                double pos;

                pos = Canvas.GetTop(enemies[i]);

                if (pos >= 950)
                    del = i;

                Canvas.SetTop(enemies[i], pos + 1);

                Rect curr = new Rect(new Point(Canvas.GetLeft(enemies[i]), Canvas.GetTop(enemies[i])), new Point(Canvas.GetLeft(enemies[i]) + 45, Canvas.GetTop(enemies[i]) + 75));

                Rect curr2 = new Rect(new Point(Canvas.GetLeft(ship), Canvas.GetTop(ship)), new Point(Canvas.GetLeft(ship) + 50, Canvas.GetTop(ship) + 90));

                if (curr.IntersectsWith(curr2))
                {
                    playground.Children.Clear();
                    bullet_time.Stop();
                    enemy_bullet_time.Stop();
                    move_shoot_time.Stop();
                    new_ship_time.Stop();
                    bullets.Clear();
                    enemies.Clear();
                    Background = new ImageBrush(new BitmapImage(new Uri(System.AppDomain.CurrentDomain.BaseDirectory + "/death_screen.jpg")));
                    TextBlock t = score_text;
                    t.Margin = new Thickness(700, 650, 0, 0);
                    t.FontSize = 20;
                    save_game();
                }

            }
            for (int i = 0; i <= del; ++i)
            {
                playground.Children.Remove(enemies[i]);
            }
            if (del >= 0)
            {
                enemies.RemoveRange(0, del);
                enemies_type.RemoveRange(0, del);
            }
        }

        private void Update_bonus()
        {
            if (exists_bonus == 0)
                return;

            Canvas playground = playground_canvas;

            double pos = Canvas.GetTop(Bonus);

            Canvas.SetTop(Bonus, pos + 2);


            Rect curr = new Rect(new Point(Canvas.GetLeft(Bonus), Canvas.GetTop(Bonus)), new Point(Canvas.GetLeft(Bonus) + 30, Canvas.GetTop(Bonus) + 30));

            Rect curr2 = new Rect(new Point(Canvas.GetLeft(ship), Canvas.GetTop(ship)), new Point(Canvas.GetLeft(ship) + 50, Canvas.GetTop(ship) + 90));

            if (curr.IntersectsWith(curr2))
            {
                shoot_upgrade++;
                playground.Children.Remove(Bonus);
                exists_bonus = 0;
            }
            if (shoot_upgrade > 3)
                curr_score += 15;

            if (pos > 950)
            {
                playground.Children.Remove(Bonus);
                exists_bonus = 0;
            }
        }

        private void statistics_button_Click(object sender, RoutedEventArgs e)
        {
            ImageBrush a = new ImageBrush(new BitmapImage(new Uri(System.AppDomain.CurrentDomain.BaseDirectory + "/statistics&credits_background.jpg")));
            a.Stretch = Stretch.UniformToFill;
            Background = a;
            TextBlock t1 = menu_text;
            t1.Visibility = Visibility.Hidden;
            Button b1 = fight_button;
            b1.Visibility = Visibility.Hidden;
            Button b2 = statistics_button;
            b2.Visibility = Visibility.Hidden;
            Button b3 = credits_button;
            b3.Visibility = Visibility.Hidden;
            Button b4 = exit_button;
            b4.Visibility = Visibility.Hidden;
            Button b5 = back_button;
            b5.Visibility = Visibility.Visible;

            TextBlock title = new TextBlock();
            title.Text = "Statistics";
            title.FontSize = 40;
            title.Visibility = Visibility.Visible;
            title.VerticalAlignment = VerticalAlignment.Top;
            title.HorizontalAlignment = HorizontalAlignment.Center;
            title.TextAlignment = TextAlignment.Center;
            title.Foreground = new SolidColorBrush(Colors.White);
            title.FontWeight = FontWeights.Heavy;
            Canvas playground = playground_canvas;
            playground.Children.Add(title);
            Canvas.SetLeft(title, 650);
            Canvas.SetTop(title, 200);
            playground.Visibility = Visibility.Visible;

            save_data info = load_game();

            TextBlock high_score_text = new TextBlock();
            high_score_text.Text = "High Score : " + info.high_score.ToString();
            high_score_text.FontSize = 25;
            high_score_text.Visibility = Visibility.Visible;
            high_score_text.VerticalAlignment = VerticalAlignment.Top;
            high_score_text.HorizontalAlignment = HorizontalAlignment.Center;
            high_score_text.TextAlignment = TextAlignment.Center;
            high_score_text.Foreground = new SolidColorBrush(Colors.White);
            playground.Children.Add(high_score_text);
            Canvas.SetLeft(high_score_text, 650);
            Canvas.SetTop(high_score_text, 300);

            TextBlock games_played_text = new TextBlock();
            games_played_text.Text = "Deaths : " + info.games_played.ToString();
            games_played_text.FontSize = 25;
            games_played_text.Visibility = Visibility.Visible;
            games_played_text.VerticalAlignment = VerticalAlignment.Top;
            games_played_text.HorizontalAlignment = HorizontalAlignment.Center;
            games_played_text.TextAlignment = TextAlignment.Center;
            games_played_text.Foreground = new SolidColorBrush(Colors.White);
            playground.Children.Add(games_played_text);
            Canvas.SetLeft(games_played_text, 650);
            Canvas.SetTop(games_played_text, 350);

            TextBlock total_bullets_text = new TextBlock();
            total_bullets_text.Text = "Total Bullets shot : " + info.total_bullets.ToString();
            total_bullets_text.FontSize = 25;
            total_bullets_text.Visibility = Visibility.Visible;
            total_bullets_text.VerticalAlignment = VerticalAlignment.Top;
            total_bullets_text.HorizontalAlignment = HorizontalAlignment.Center;
            total_bullets_text.TextAlignment = TextAlignment.Center;
            total_bullets_text.Foreground = new SolidColorBrush(Colors.White);
            playground.Children.Add(total_bullets_text);
            Canvas.SetLeft(total_bullets_text, 650);
            Canvas.SetTop(total_bullets_text, 400);

            TextBlock killed_1_text = new TextBlock();
            killed_1_text.Text = "Non - shooting enemies destroyed : " + info.killed_1.ToString();
            killed_1_text.FontSize = 25;
            killed_1_text.Visibility = Visibility.Visible;
            killed_1_text.VerticalAlignment = VerticalAlignment.Top;
            killed_1_text.HorizontalAlignment = HorizontalAlignment.Center;
            killed_1_text.TextAlignment = TextAlignment.Center;
            killed_1_text.Foreground = new SolidColorBrush(Colors.White);
            playground.Children.Add(killed_1_text);
            Canvas.SetLeft(killed_1_text, 650);
            Canvas.SetTop(killed_1_text, 450);

            TextBlock killed_2_text = new TextBlock();
            killed_2_text.Text = "Shooting enemies destroyed : " + info.killed_2.ToString();
            killed_2_text.FontSize = 25;
            killed_2_text.Visibility = Visibility.Visible;
            killed_2_text.VerticalAlignment = VerticalAlignment.Top;
            killed_2_text.HorizontalAlignment = HorizontalAlignment.Center;
            killed_2_text.TextAlignment = TextAlignment.Center;
            killed_2_text.Foreground = new SolidColorBrush(Colors.White);
            playground.Children.Add(killed_2_text);
            Canvas.SetLeft(killed_2_text, 650);
            Canvas.SetTop(killed_2_text, 500);

            SpeechSynthesizer voice = new SpeechSynthesizer();
            voice.SelectVoiceByHints(VoiceGender.Female, VoiceAge.Teen);
            voice.SpeakAsync("Your high score is" + info.high_score.ToString() + "points");
        }

        private void credits_button_Click(object sender, RoutedEventArgs e)
        {
            ImageBrush a = new ImageBrush(new BitmapImage(new Uri(System.AppDomain.CurrentDomain.BaseDirectory + "/statistics&credits_background.jpg")));
            a.Stretch = Stretch.UniformToFill;
            Background = a;
            TextBlock t1 = menu_text;
            t1.Visibility = Visibility.Hidden;
            TextBlock t2 = credits_text;
            t2.Visibility = Visibility.Visible;
            Button b1 = fight_button;
            b1.Visibility = Visibility.Hidden;
            Button b2 = statistics_button;
            b2.Visibility = Visibility.Hidden;
            Button b3 = credits_button;
            b3.Visibility = Visibility.Hidden;
            Button b4 = exit_button;
            b4.Visibility = Visibility.Hidden;
            Button b5 = back_button;
            b5.Visibility = Visibility.Visible;

            SpeechSynthesizer voice = new SpeechSynthesizer();
            voice.SelectVoiceByHints(VoiceGender.Female, VoiceAge.Teen);
            voice.SpeakAsync("Developed by Mr Dino");
        }

        private void back_button_Click(object sender, RoutedEventArgs e)
        {
            ImageBrush a = new ImageBrush(new BitmapImage(new Uri(System.AppDomain.CurrentDomain.BaseDirectory + "/menu_background.jpg")));
            a.Stretch = Stretch.UniformToFill;
            Background = a;
            TextBlock t1 = menu_text;
            TextBlock t3 = score_text;
            t3.Visibility = Visibility.Hidden;  
            t1.Visibility = Visibility.Visible;
            TextBlock t2 = credits_text;
            t2.Visibility = Visibility.Hidden;
            Button b1 = fight_button;
            b1.Visibility = Visibility.Visible;
            Button b2 = statistics_button;
            b2.Visibility = Visibility.Visible;
            Button b3 = credits_button;
            b3.Visibility = Visibility.Visible;
            Button b4 = exit_button;
            b4.Visibility = Visibility.Visible;
            Button b5 = back_button;
            b5.Visibility = Visibility.Hidden;
            b5.Margin = new Thickness(700, 700, 700, 0);
            Canvas playground = playground_canvas;
            playground.Visibility = Visibility.Hidden;
            playground.Children.Clear();
            bullet_time.Stop();
            move_shoot_time.Stop();
            new_ship_time.Stop();
            enemy_bullet_time.Stop();
            enemies_type.Clear();
            enemy_bullets.Clear();
            bullets.Clear();
            enemies.Clear();
            shoot_upgrade = 0;
        }

        private void exit_button_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }

        private void fight_button_Click(object sender, RoutedEventArgs e)
        {
            ImageBrush a = new ImageBrush(new BitmapImage(new Uri(System.AppDomain.CurrentDomain.BaseDirectory + "/game_background.jpg")));
            a.Stretch = Stretch.UniformToFill;
            Background = a;
            TextBlock t2 = score_text;
            t2.Visibility = Visibility.Visible;
            t2.Margin = new Thickness(5, 5, 0, 0);
            t2.Text = "Score : 0";
            t2.FontSize = 16;
            TextBlock t1 = menu_text;
            t1.Visibility = Visibility.Hidden;
            Button b1 = fight_button;
            b1.Visibility = Visibility.Hidden;
            Button b2 = statistics_button;
            b2.Visibility = Visibility.Hidden;
            Button b3 = credits_button;
            b3.Visibility = Visibility.Hidden;
            Button b4 = exit_button;
            b4.Visibility = Visibility.Hidden;
            Button b5 = back_button;
            b5.Visibility = Visibility.Visible;
            b5.Margin = new Thickness(1410, 5, 5, 0);
            new_game();
        }

        public void new_game()
        {
            game_enemies = 0;
            another = 0;
            curr_score = 0;
            total_bullets = 0;
            killed_1 = 0;
            killed_2 = 0;

            save_data info = load_game();
            last_high_score = info.high_score;

            start_time = DateTime.Now;

            Canvas playground = playground_canvas;
            playground.Visibility = Visibility.Visible;
            if (!ok)
            {
                ship.Source = new BitmapImage(new Uri(System.AppDomain.CurrentDomain.BaseDirectory + "/spaceship.jpg"));
                ship.Width = 50;
                ship.Height = 90;
                playground.Children.Add(ship);
            }

            ship_position = 700;
            ship_height = 810;
            Canvas.SetLeft(ship, ship_position);
            Canvas.SetTop(ship, 810);

            bullet_time.Interval = TimeSpan.FromMilliseconds(20);
            bullet_time.Start();

            move_shoot_time.Interval = TimeSpan.FromMilliseconds(1);
            move_shoot_time.Start();

            new_ship_time.Interval = TimeSpan.FromSeconds(6);
            new_ship_time.Start();

            enemy_bullet_time.Interval = TimeSpan.FromMilliseconds(50);
            enemy_bullet_time.Start();

            Bonus.Source = new BitmapImage(new Uri(System.AppDomain.CurrentDomain.BaseDirectory + "/bonus.png"));
            Bonus.Width = 30;
            Bonus.Height = 30;

            if (!File.Exists("saved_data.dat"))
            {
                SpeechSynthesizer voice = new SpeechSynthesizer();
                voice.SpeakAsync("use arrows to slide and s key to shoot");
                voice.Speak("good luck");
                voice.SpeakAsync("blue ships shoot at you, but destroying them adds 2 points to score");
            }
        }

        private void add_enemy(object sender, EventArgs e)
        {
            int a = DateTime.Now.Millisecond;
            if (a % 3 == 0)
            {
                ++game_enemies;
                Random generator = new Random();
                Canvas playground = playground_canvas;
                int pos = generator.Next(5, Math.Max(5, 1440 - 50 * (game_enemies - 1)));
                string path_to_enemy = null;
                int type = 0;
                switch (DateTime.Now.Millisecond % 4)
                {
                    case 0:
                        type = 2;
                        path_to_enemy = System.AppDomain.CurrentDomain.BaseDirectory + "/enemy_2.png";
                        break;
                    default:
                        path_to_enemy = System.AppDomain.CurrentDomain.BaseDirectory + "/enemy_1.png";
                        type = 1;
                        break;
                }
                for (int i = 0; i < game_enemies && pos <= 1440; ++i)
                {
                    Image enemy = new Image();
                    enemy.Source = new BitmapImage(new Uri(path_to_enemy));
                    enemy.Height = 80;
                    enemy.Width = 45;
                    enemies.Add(enemy);
                    enemies_type.Add(type);
                    playground.Children.Add(enemies[enemies.Count - 1]);
                    Canvas.SetLeft(enemies[enemies.Count - 1], pos);
                    Canvas.SetTop(enemies[enemies.Count - 1], -80);
                    pos += 50;
                }
            }
            else
            if (a % 3 == 1)
            {
                Canvas playground = playground_canvas;
                if (game_enemies >= 7)
                {
                    Random gen = new Random();
                    int left = gen.Next(300, 800);
                    int right = left;
                    string path_to_enemy = null;
                    int type = 0;
                    switch (DateTime.Now.Millisecond % 2)
                    {
                        case 0:
                            type = 2;
                            path_to_enemy = System.AppDomain.CurrentDomain.BaseDirectory + "/enemy_2.png";
                            break;
                        default:
                            path_to_enemy = System.AppDomain.CurrentDomain.BaseDirectory + "/enemy_1.png";
                            type = 1;
                            break;
                    }
                    Image enemy = new Image();
                    enemy.Source = new BitmapImage(new Uri(path_to_enemy));
                    enemy.Height = 80;
                    enemy.Width = 45;
                    enemies.Add(enemy);
                    enemies_type.Add(type);
                    playground.Children.Add(enemies[enemies.Count - 1]);
                    Canvas.SetLeft(enemies[enemies.Count - 1], left);
                    Canvas.SetTop(enemies[enemies.Count - 1], -80);
                    left -= 50;
                    right += 50;
                    for (int i = 1; i <= game_enemies / 2 && left > 100 && right < 1300; ++i)
                    {
                        switch (DateTime.Now.Millisecond % 2)
                        {
                            case 0:
                                type = 2;
                                path_to_enemy = System.AppDomain.CurrentDomain.BaseDirectory + "/enemy_2.png";
                                break;
                            default:
                                path_to_enemy = System.AppDomain.CurrentDomain.BaseDirectory + "/enemy_1.png";
                                type = 1;
                                break;
                        }
                        Image enemy1 = new Image();
                        enemy1.Source = new BitmapImage(new Uri(path_to_enemy));
                        enemy1.Height = 80;
                        enemy1.Width = 45;
                        enemies.Add(enemy1);
                        enemies_type.Add(type);
                        playground.Children.Add(enemies[enemies.Count - 1]);
                        Canvas.SetLeft(enemies[enemies.Count - 1], left);
                        Canvas.SetTop(enemies[enemies.Count - 1], -80 - i * 20);


                        switch (DateTime.Now.Millisecond % 2)
                        {
                            case 0:
                                type = 2;
                                path_to_enemy = System.AppDomain.CurrentDomain.BaseDirectory + "/enemy_2.png";
                                break;
                            default:
                                path_to_enemy = System.AppDomain.CurrentDomain.BaseDirectory + "/enemy_1.png";
                                type = 1;
                                break;
                        }
                        Image enemy2 = new Image();
                        enemy2.Source = new BitmapImage(new Uri(path_to_enemy));
                        enemy2.Height = 80;
                        enemy2.Width = 45;
                        enemies.Add(enemy2);
                        enemies_type.Add(type);
                        playground.Children.Add(enemies[enemies.Count - 1]);
                        Canvas.SetLeft(enemies[enemies.Count - 1], right);
                        Canvas.SetTop(enemies[enemies.Count - 1], -80 - i * 20);

                        left -= 50;
                        right += 50;
                    }
                }
                else
                {
                    string path_to_enemy1 = System.AppDomain.CurrentDomain.BaseDirectory + "/enemy_1.png";
                    string path_to_enemy2 = System.AppDomain.CurrentDomain.BaseDirectory + "/enemy_2.png";
                    Random gen = new Random();
                    for (int i = 1; i <= 7; i += 2)
                    {
                        Image enemy = new Image();
                        enemy.Source = new BitmapImage(new Uri(path_to_enemy1));
                        enemy.Height = 80;
                        enemy.Width = 45;
                        enemies.Add(enemy);
                        enemies_type.Add(1);
                        playground.Children.Add(enemies[enemies.Count - 1]);
                        Canvas.SetLeft(enemies[enemies.Count - 1], gen.Next(150 * i + 45, 150 * (i + 1)));
                        Canvas.SetTop(enemies[enemies.Count - 1], -80);

                        Image enemy1 = new Image();
                        enemy1.Source = new BitmapImage(new Uri(path_to_enemy2));
                        enemy1.Height = 80;
                        enemy1.Width = 45;
                        enemies.Add(enemy1);
                        enemies_type.Add(2);
                        playground.Children.Add(enemies[enemies.Count - 1]);
                        Canvas.SetLeft(enemies[enemies.Count - 1], gen.Next(150 * (i + 1) + 45, 150 * (i + 2)));
                        Canvas.SetTop(enemies[enemies.Count - 1], -70);
                    }
                }
            }
            else
            if (a % 3 == 2)
            {
                ++game_enemies;
                if (a % 2 == 0)
                {
                    Random gen = new Random();
                    int pos = gen.Next(15, 300);
                    for (int i = 0; i < game_enemies && pos < 1400; ++i)
                    {
                        string path_to_enemy = null;
                        int type = 0;
                        switch (DateTime.Now.Millisecond % 2)
                        {
                            case 0:
                                type = 2;
                                path_to_enemy = System.AppDomain.CurrentDomain.BaseDirectory + "/enemy_2.png";
                                break;
                            default:
                                path_to_enemy = System.AppDomain.CurrentDomain.BaseDirectory + "/enemy_1.png";
                                type = 1;
                                break;
                        }

                        Canvas playground = playground_canvas;
                        Image enemy = new Image();
                        enemy.Source = new BitmapImage(new Uri(path_to_enemy));
                        enemy.Height = 80;
                        enemy.Width = 45;
                        enemies.Add(enemy);
                        enemies_type.Add(type);
                        playground.Children.Add(enemies[enemies.Count - 1]);
                        Canvas.SetLeft(enemies[enemies.Count - 1], pos);
                        Canvas.SetTop(enemies[enemies.Count - 1], -80 - gen.Next(10, 100));
                        pos += gen.Next(45, 100);
                    }
                }
                else
                {
                    Random gen = new Random();
                    int pos = gen.Next(15, 500);
                    for (int i = 0; i < game_enemies && pos < 1400; ++i)
                    {
                        string path_to_enemy = null;
                        int type = 0;
                        switch (DateTime.Now.Millisecond % 2)
                        {
                            case 0:
                                type = 2;
                                path_to_enemy = System.AppDomain.CurrentDomain.BaseDirectory + "/enemy_2.png";
                                break;
                            default:
                                path_to_enemy = System.AppDomain.CurrentDomain.BaseDirectory + "/enemy_1.png";
                                type = 1;
                                break;
                        }

                        Canvas playground = playground_canvas;
                        Image enemy = new Image();
                        enemy.Source = new BitmapImage(new Uri(path_to_enemy));
                        enemy.Height = 80;
                        enemy.Width = 45;
                        enemies.Add(enemy);
                        enemies_type.Add(type);
                        playground.Children.Add(enemies[enemies.Count - 1]);
                        Canvas.SetLeft(enemies[enemies.Count - 1], pos);
                        Canvas.SetTop(enemies[enemies.Count - 1], -80 - i * 30);
                        pos += 50;
                    }
                }
            }

        }

        private void exit(object o, KeyEventArgs e)
        {
            if (Keyboard.IsKeyDown(Key.Escape))
            {

                object a = new object();
                RoutedEventArgs b = new RoutedEventArgs();
                back_button_Click(a, b);
            }
        }

        private void shoot(object sender, EventArgs e)
        {
            if (Keyboard.IsKeyDown(Key.S))
            {
                if (DateTime.Now.Subtract(last_bullet).TotalMilliseconds >= 265)
                {
                    MediaPlayer a = new MediaPlayer();
                    a.Open(new Uri(AppDomain.CurrentDomain.BaseDirectory + "/shoot.wav"));
                    a.Play();
                    Task.Delay(200).ContinueWith(_=>
                        { a.Stop(); });
                    if (shoot_upgrade == 0)
                    {
                        ++total_bullets;
                        last_bullet = DateTime.Now;
                        Image bullet = new Image();
                        bullet.Source = new BitmapImage(new Uri(System.AppDomain.CurrentDomain.BaseDirectory + "/bullet.png"));
                        bullet.Width = 8;
                        bullet.Height = 20;
                        bullets.Add(bullet);
                        Canvas playground = playground_canvas;
                        playground.Children.Add(bullets[bullets.Count - 1]);
                        Canvas.SetLeft(bullets[bullets.Count - 1], ship_position + 21);
                        Canvas.SetTop(bullets[bullets.Count - 1], ship_height - 5);
                    }
                    else
                    if (shoot_upgrade == 1)
                    {
                        ++total_bullets;
                        last_bullet = DateTime.Now;
                        Image bullet = new Image();
                        bullet.Source = new BitmapImage(new Uri(System.AppDomain.CurrentDomain.BaseDirectory + "/bullet.png"));
                        bullet.Width = 8;
                        bullet.Height = 20;
                        bullets.Add(bullet);
                        Canvas playground = playground_canvas;
                        playground.Children.Add(bullets[bullets.Count - 1]);
                        Canvas.SetLeft(bullets[bullets.Count - 1], ship_position + 5);
                        Canvas.SetTop(bullets[bullets.Count - 1], ship_height - 5);

                        ++total_bullets;
                        last_bullet = DateTime.Now;
                        bullet = new Image();
                        bullet.Source = new BitmapImage(new Uri(System.AppDomain.CurrentDomain.BaseDirectory + "/bullet.png"));
                        bullet.Width = 8;
                        bullet.Height = 20;
                        bullets.Add(bullet);
                        playground.Children.Add(bullets[bullets.Count - 1]);
                        Canvas.SetLeft(bullets[bullets.Count - 1], ship_position + 37);
                        Canvas.SetTop(bullets[bullets.Count - 1], ship_height - 5);
                    }
                    else
                    {
                        ++total_bullets;
                        last_bullet = DateTime.Now;
                        Image bullet = new Image();
                        bullet.Source = new BitmapImage(new Uri(System.AppDomain.CurrentDomain.BaseDirectory + "/bullet.png"));
                        bullet.Width = 8;
                        bullet.Height = 20;
                        bullets.Add(bullet);
                        Canvas playground = playground_canvas;
                        playground.Children.Add(bullets[bullets.Count - 1]);
                        Canvas.SetLeft(bullets[bullets.Count - 1], ship_position + 5);
                        Canvas.SetTop(bullets[bullets.Count - 1], ship_height - 5);

                        ++total_bullets;
                        last_bullet = DateTime.Now;
                        bullet = new Image();
                        bullet.Source = new BitmapImage(new Uri(System.AppDomain.CurrentDomain.BaseDirectory + "/bullet.png"));
                        bullet.Width = 8;
                        bullet.Height = 20;
                        bullets.Add(bullet);
                        playground.Children.Add(bullets[bullets.Count - 1]);
                        Canvas.SetLeft(bullets[bullets.Count - 1], ship_position + 22);
                        Canvas.SetTop(bullets[bullets.Count - 1], ship_height - 10);


                        ++total_bullets;
                        last_bullet = DateTime.Now;
                        bullet = new Image();
                        bullet.Source = new BitmapImage(new Uri(System.AppDomain.CurrentDomain.BaseDirectory + "/bullet.png"));
                        bullet.Width = 8;
                        bullet.Height = 20;
                        bullets.Add(bullet);
                        playground.Children.Add(bullets[bullets.Count - 1]);
                        Canvas.SetLeft(bullets[bullets.Count - 1], ship_position + 37);
                        Canvas.SetTop(bullets[bullets.Count - 1], ship_height - 5);
                    }
                }
            }
        }

        private void enemy_shoot(object sender, EventArgs e)
        {
            ++enemy_shooters;
            Canvas playground = playground_canvas;

            for (int i = 0, j = 0; i < enemies_type.Count && j < enemy_shooters; ++j, i += (DateTime.Now.Second % 2) + 1)
                if (enemies_type[i] == 2)
                {
                    double top = Canvas.GetTop(enemies[i]);
                    double left = Canvas.GetLeft(enemies[i]);

                    string path = null;
                    if (DateTime.Now.Millisecond % 2 == 0)
                        path = System.AppDomain.CurrentDomain.BaseDirectory + "/enemy_bullet_1.png";
                    else
                        path = System.AppDomain.CurrentDomain.BaseDirectory + "/enemy_bullet_2.png";
                    Image new_bullet = new Image();
                    new_bullet.Source = new BitmapImage(new Uri(path));
                    new_bullet.Width = 15;
                    new_bullet.Height = 15;
                    enemy_bullets.Add(new_bullet);
                    playground.Children.Add(enemy_bullets[enemy_bullets.Count - 1]);
                    Canvas.SetLeft(enemy_bullets[enemy_bullets.Count - 1], left + 15);
                    Canvas.SetTop(enemy_bullets[enemy_bullets.Count - 1], top + 85);
                }
        }

        private void update_enemy_bullet(object sender, EventArgs e)
        {
            Canvas playground = playground_canvas;
            for (int i = 0; i < enemy_bullets.Count; ++i)
            {
                double pos;

                pos = Canvas.GetTop(enemy_bullets[i]);

                if (pos >= 950)
                {
                    playground.Children.Remove(enemy_bullets[i]);
                    enemy_bullets.RemoveAt(i);
                    --i;
                    continue;
                }
                Canvas.SetTop(enemy_bullets[i], pos + 5);

                Rect curr = new Rect(new Point(Canvas.GetLeft(enemy_bullets[i]), Canvas.GetTop(enemy_bullets[i])), new Point(Canvas.GetLeft(enemy_bullets[i]) + 15, Canvas.GetTop(enemy_bullets[i]) + 15));

                Rect curr2 = new Rect(new Point(Canvas.GetLeft(ship), Canvas.GetTop(ship)), new Point(Canvas.GetLeft(ship) + 50, Canvas.GetTop(ship) + 90));

                if (curr.IntersectsWith(curr2))
                {
                    playground.Children.Clear();
                    bullet_time.Stop();
                    enemy_bullet_time.Stop();
                    move_shoot_time.Stop();
                    new_ship_time.Stop();
                    bullets.Clear();
                    enemies.Clear();
                    Background = new ImageBrush(new BitmapImage(new Uri(System.AppDomain.CurrentDomain.BaseDirectory + "/death_screen.jpg")));
                    TextBlock t = score_text;
                    t.Margin = new Thickness(700, 650, 0, 0);
                    t.FontSize = 20;
                    save_game();
                }
            }
        }
    }
}