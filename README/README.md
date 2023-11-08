<H1>Raycasting Basic</H1>


Raycasting is a rendering technique to create a 3D perspective in a 2D map.
Basic of RayCasting => map is a 2D square grid that contains 0 (no walls)
and positive value (walls).

We send a ray from the player position and check every few steps if a wall has 
been hit. If it has, we calculate the height of the wall, else, we keep going.
This method has a big inconvenient, it neccessitate a lot a calculation at every
position from the player.

In order to have the correct calculation without frying the machine, we use the 
DDA Algorithm : ` In computer graphics, a digital differential analyzer (DDA) is 
hardware or software used for interpolation of variables over an interval between 
start and end point. DDAs are used for rasterization of lines, triangles and polygons.` (Wikipedia definition).

If we are to use this algorithm then several vector will be needed : one for the player
direction and one for the camera plane.
<ol><B>Player direction vector</B>: Position is determined by two values x and y coordinates. And now another vector is used to determine the direction of the player with x and y coordinates. The length of the direction vector doesnt matter, only
the direction : multiplying x and y by the same value changes the length but keeps
the direction.</ol>
<ol><B>Camera plane vector</B>: In a 2D map the camera plane is a line rather and can be represented with a single vector. The camera plane should alway be perpendicular on the direction vector. It represent the surface of the computer screen, while the direction vector points inside the screen.</ol>

A ray casted is easily calculated out of the camera: it's the sum of the direction vector of the camera and a part of the plane vector. For example a ray casted on a third of the length of the camera plane would have  direction of `dir + plane * 1/3`.
This ray direction vector is the vector rayDir and the X and Y component of this vector are then used by the DDA algorithm.

The two outer lines, left and right border of the screen, with the angle between those lines is called the <B>Field of vision</B> or FOV. The FOV is determinated by the ratio of the lenght of the direction vector, and the lenght of the plane. For example :
<ul>If the direction vector and the camera plane vector have the same lenght, the FOV will be 90°.</ul>
<ul>If the direction vector is much longer than the camera plane, the FOV will be much smaller than 90°, and you'll have a very narrow vision. You'll see everything more detailed though and there will be less depth, so this is the same as zooming in.</ul>
<ul>If the direction vector is shorter than the camera plane, the FOV will be larger than 90° (with a maximum of 180°) and you'll have a much wider vision.</ul>
<ul>When the player rotates, the camera has to rotate, so both the direction vector and the plane vector have to be rotated as well. To rotate a vector, multiply it with the rotation matrix : 
`[cos(a) - sin(a)]
 [sin(a) - cos(a)]`</ul>


<H1>Sources:</H1>
<ul><a href="https://lodev.org/cgtutor/raycasting.html">Raycasting Basic</a></ul>
<ul><a href="https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)">Digital Differential Analyzer</a></ul>
<ul><a href="https://github.com/Saxsori/ray-cast">More human comprehension of raycasting</a></ul>
<ul><a href="https://harm-smits.github.io/42docs/libs/minilibx">Minilibx docs</a></ul>
<ul><a href="https://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h">Keysyms</a></ul>