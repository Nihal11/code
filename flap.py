import math
import simplegui
import random

#image of the bird
bird_image = simplegui.load_image("http://1.bp.blogspot.com/-3PnObQzb_UE/Uwrc-2Or-aI/AAAAAAAADKY/h-It2dBTYQU/s1600/tumblr_n0dw9jUXOD1s6294bo1_r2_500.png")
pipe_image = simplegui.load_image("http://www.clker.com/cliparts/T/R/h/S/4/i/a-green-cartoon-pipe-md.png")
pipe_group = set([])
pipe_count = 0
pipe_needed = True

class Bird:
    def __init__(self):
        self.velocity = 0
        self.gravity = 0.4
        self.pos = [200,200]
        self.image = bird_image
        self.width = self.image.get_width()
        self.height = self.image.get_height()
        self.image_center = [self.width//2, self.height//2]
        self.image_size = [self.width, self.height]
        self.alive = True
        self.radius = self.width/20
        
    def draw(self, canvas):
        self.pos[1] += self.velocity
        self.velocity += self.gravity
        
        if self.pos[1] >= 450:
            self.velocity = 0
            self.alive = False
     
        canvas.draw_image(self.image,self.image_center, self.image_size, self.pos, [self.image_size[0]/5, self.image_size[1]/5])

class Pipe:
    def __init__(self, position):
        self.image = pipe_image
        self.width = self.image.get_width()
        self.height = self.image.get_height()
        self.center = [self.width//2, self.height//2]
        self.image_size = [self.width, self.height-190]
        self.pos = [900, position]
        self.scaled_height = 500
        self.gap = 200
        self.pos2 = [self.pos[0], self.pos[1] - self.scaled_height - self.gap]
        self.cap_center = [self.width//2, 45]
        self.cap_size = [self.width, 85]
        self.cap_pos = [self.pos[0], self.pos[1] - self.scaled_height/2 + 20]
        
    def draw(self, canvas):
        global pipe_needed, my_bird
        self.pos[0] -= 2
        self.pos2[0] -= 2
        self.cap_pos[0] -= 2
        canvas.draw_image(self.image, self.center, self.image_size, self.pos, [self.width/2, self.scaled_height])
        canvas.draw_image(self.image, self.center, self.image_size, self.pos2, [self.width/2, self.scaled_height])
        canvas.draw_image(self.image, self.cap_center, self.cap_size, self.cap_pos, [self.width/2 - 20, 40])
        canvas.draw_image(self.image, self.cap_center, self.cap_size, [self.cap_pos[0], self.cap_pos[1]-self.gap - 40], [self.width/2 - 20, 40])
        
        if (my_bird.pos[0] + my_bird.radius >= self.pos[0] - self.width/4 and my_bird.pos[0] + my_bird.radius <= self.pos[0] + self.width/4 and my_bird.pos[1] + my_bird.radius >= self.pos[1] - self.scaled_height/2) or (my_bird.pos[0] + my_bird.radius >= self.pos2[0] - self.width/4 and my_bird.pos[0] + my_bird.radius <= self.pos2[0] + self.width/4 and my_bird.pos[1] - my_bird.radius <= self.pos2[1] + self.scaled_height/2):
               print 1
            
        ''' test statements ''' 
        canvas.draw_circle([my_bird.pos[0] + my_bird.radius, my_bird.pos[1] + 0*my_bird.radius], 5, 2, 'White')
        
        
def draw(canvas):
    my_bird.draw(canvas)
    '''first_pipe.draw(canvas)'''
    for pipe in set(pipe_group):
        pipe.draw(canvas)
    
    for pipe in set(pipe_group):
        if  pipe.pos[0] < -(pipe.width + 100):
            pipe_group.remove(pipe)
            
        
def keydown(key):
    if key == simplegui.KEY_MAP['space'] and my_bird.alive:
        my_bird.velocity = -7
        
def pipe_spawner():
    global pipe_group, pipe_count, pipe_needed
    '''if pipe_needed:'''
    pipe_group.add(Pipe(random.randrange(450, 700, 50)))
    '''    pipe_count += 1
        pipe_count %= 4
        pipe_needed = False'''

my_bird = Bird()
'''first_pipe = Pipe(random.randrange(450,700,20))'''
pipe_spawner()

frame = simplegui.create_frame('Flappy Birds', 800,500)
frame.set_draw_handler(draw)
frame.set_keydown_handler(keydown)
frame.start()

timer = simplegui.create_timer(2500, pipe_spawner)
timer.start()