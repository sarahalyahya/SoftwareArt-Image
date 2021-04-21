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

<h3>Process</h3>
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
      ```
 </br>
As you can see, I'm using a modulo if-statement to scatter the tiny lines all over.

      
      

