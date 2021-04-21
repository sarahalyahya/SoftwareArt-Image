<h1>Assignment 2 - Motion: Experiments with Perlin Noise</h1>
<h3>Still</h3>
<img src = bin/data/Still.PNG>
<h3>Link</h3>
https://youtu.be/1sbha64iXPg

<h3>Inspiration</h3>
For this assignment, I gathered inspiration from an old Processing sketch I made a few months ago as well as the visuals that the band 'Tame Imapala' uses, specifically in their music video for 'Feels Like We Only Go Backwards". 
</br>
Here's my old sketch: https://www.youtube.com/watch?v=cmjDk15F9WI
As for the band visuals, here are some stills and cover art so you can get the general feel of what I was going for:
<img src = bin/data/mvStill.PNG width= 50% height = 50%>
<h5>Cover Art by Robert Beatty</h5>
<img src = bin/data/CurrentsTameImpala.jpg width= 50% height = 50%>
<img src = bin/data/eventuallyTameImpala.jpg width= 50% height = 50%>

<h3>Color Palette</h3>
As you can see in the music video, there's a lot of reliance on the three primary colors. So that constructed my main palette which I used for the moving background and the surrounding circles at some points. 
<img src = bin/data/mainPalette.png width= 50% height = 50%>
However, I also wanted to include a secondary palette inspired by shades of the primary colors and other colors included within the music video. I used it in circles that gradually turn to primary red as the motion repeats.

<img src = bin/data/secondaryPalette.png width = 50% height = 50%>

<h3>Process</h3>
<h4> ~ waves ~ </h4>
In my old sketch, I had used Perlin noise to simulate a wave movement. Considering that these waves and trippy shapes are a common theme in my inspiration visuals it seemed fitting to base my assignment on it this time. I started with a very basic noise grid 
</br>
``` 
for (int x = 0; x < ofGetWidth() * 2; x++) {
	for (int y = 0; y < ofGetHeight() * 2; y++) {

		//generating a (not-so-random) value so that the tiny lines have some relation to each other 
		float val = ofNoise(x * noise + randX, y * noise + randY); // larger decimal value = noisier the shape is
		if (int(val * frequency) % 4 == 0) { //frequency / range (smaller multiplication by n = blobbier shape / less range)
			ofDrawLine(x, y, x + 1, y + 1); //tiny line resembling a point


			} 
 </br>
As you can see, I'm using a modulo if-statement to scatter the tiny lines all over. After setting up a basic noise grid, I started playing around with noise values to realized that the smaller the noise value the more relation there is between the tiny lines. 
<img src = bin/data/process.png >
This led me to the wavy/cicular shapes in the background. Basically, as I played around with the variables I slowly started to understand what was happening more and more, and tinkered with my code until I achieved the desired outcome. 

<h4>Silhouette</h4>
The silhouette was a necessary addition since it's a recurring motif in the inspiration clip, I also felt like it adds to the psychedelic/ 80's visuals feel that I really liked. 
I got the png from The Noun Project, and it is designed by Maxim Kulikov.

<h4>The Circles</h4>
Although I hadn't originally planned on including these circles, the final piece felt like it needed a bit more stability and contrast from the constantly changing noise. So, I decided to frame the face with circles of colors from the secondary color palette, that slowly iterate to all become red and then restarting the cycle. This maintains some movement without making it overwhelming, and maintains the color palette. 

<h3>Final Reflection</h3>
Playing around with code is a practice that I will probably be adopting after this assignment. It was extremely rewarding to slowly figure out what is going on and connect the points together! I look forward to possibly revisiting the piece for our last assignment and figure out how I can add an element of storytelling to it!


      
      

