   M S B A M L   `   `   `  ����?  ;Dinu, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullclr-namespace:DinuDinu  5   	       Dinu.MainWindow   5   	   W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   $localclr-namespace:Dinu     5   	     � Title$
  Dinu��5   	   $
��25cm��6   $
��40cm��6$    J� SnapsToDevicePixels .  � 
ResizeMode$ NoResize=�6L    � WindowStartupLocation$ CenterScreen=�6b   ��5
      �� 5   
    �� ImageSource$ menu_background.jpg��6    j� Stretch$ UniformToFill=�68   .��5      � .+�5   
   �� -   5         ��Name$ 	menu_text��5      $��580,130,580,0q�6'   $
��Wrap=�6>   $g��aYour name is Dinu. You have to defend Terra once again.. How many enemies can you turn into dust?��6R   $	��Top=�6�   $	��120��6�   $��26(�6�   $��Cambria)�6�   $��	ExtraBold"�6   �� TextAlignment$ Center=�6   J� Effect 5      3  -System.Windows.Media.Effects.DropShadowEffect  5      	   Color$	 White��6#   
   ShadowDepth$	
 3.5Q�61   5      �� 5   
   -   5         ��Name$ fight_button��5      $��Fight��6'   $��18(�67   $��700,310,700,0q�6E   $��30��6\   $	��Top=�6h   $��Cambria)�6�   6�   �� 5   
   -   5        $ statistics_button��5      $��
Statistics��6,   $��18(�6A   $��700,380,700,0q�6O   $��30��6f   $	��Top=�6r   $��Cambria)�6�   6�   �� 5   
   -   5        $ credits_button��5      $��Credits��6)   $��18(�6;   $��700,450,700,0q�6I   $��30��6`   $	��Top=�6l   $��Cambria)�6�   6�   �� 5   
   -   5        $ exit_button��5      $
��Exit��6&   $��18(�65   $��700,520,700,0q�6C   $��30��6Z   $	��Top=�6f   $��Cambria)�6~   6�   �� 5   
   -   5        $ back_button��5      $
��Back��6&    �� 	IsDefault . $��18(�6F   $��700,700,700,0q�6T   $��30��6k   $	��Top=�6w   $��Cambria)�6�   $y�Hidden=�6�   �� 5   
   -   5        $ credits_text��5      $ Center=�6*   $��640,350,640,0q�6A   $
��Wrap=�6X   $*��$Developed by                    Dinu��6l   $	��Top=�5      $��30(�62   $��Cambria)�6@   $��	ExtraBold"�6U   $y�Hidden=�6l   �� 5   
   -   5         ��Name$ playground_canvas��5      $��0q�6,   $y�Hidden=�67   �� 5   
   -	   5        $ 
score_text��5      $��5,5,0,0q�6(   $
��Wrap=�69   $��	Score : 0��6M   $	��Top=�6^   $
��Left=�6v   
�������$��16(�6�   $y�Hidden=�6�   5      5       