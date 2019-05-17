import numpy as np
import matplotlib.pyplot as plt
import matplotlib.patches as patches
from mpl_toolkits.mplot3d import Axes3D
import visutils #provided visutils.py contains some helper functions for 3d

class Camera:
        """
        A simple data structure describing camera parameters
        The parameters describing the camera
        cam.f : float --- camera focal length (in units of pixels)
        cam.c : 2x1 vector --- offset of principle point
        cam.R : 3x3 matrix --- camera rotation
        cam.t : 3x1 vector --- camera translation
        """

    def __init__(self,f,c,R,t):
        self.f = f
        self.c = c
        self.R = R
        self.t = t

    def project(self,pts3):

        """
        Project the given 3D points in world coordinates into the specified
        Parameters
        ----------
        pts3 : 2D numpy.array (dtype=float)
        Coordinates of N points stored in a array of shape (3,N)
        Returns
        -------
        pts2 : 2D numpy.array (dtype=float)
        Image coordinates of N points stored in an array of shape (2,N)
        """
        assert(pts3.shape[0]==3)
        #
        # your code goes here
        #
        assert(pts2.shape[1]==pts3.shape[1])
        assert(pts2.shape[0]==2)

        return pts24

    def generate_hemisphere(radius,center,npts):
        """
        Generate a set of 3D points which are randomly distributed on the
        surface of a hemisphere for purposes of testing your code.
        Parameters
        ----------
        radius : float
        Hemisphere radius
        center : numpy.array (dtype=float)
        3x1 vector specifying the center of the hemisphere
        npts : int
        number of points to generate
        Returns
        -------
        x : 2D numpy.array (dtype=float)
        (3,npts) array containing coordinates of the points
        """
        assert(center.shape==(3,1))
        #generate randomly distributed points
        x = np.random.standard_normal((3,npts))
        #scale points to the surface of a sphere with given radius
        nx = np.sqrt(np.sum(x*x,axis=0))
        x = radius * x / nx
        # make points with positive z-coordinates negative
        # so that points are all on a half-sphere
        x[2,:] = -np.abs(x[2,:])
        # translate to desired position
        x = x + center
        return x
        #
        # test your camera and project function
        #
        # generate 500 3D points on a hemisphere of radius 1 at
        # a location 5 units along the z axis and 5 units along
        # the y axis.


    pts3 = generate_hemisphere(...)
    # create the camera with the desired parameters
    cam = Camera(...)
    # call the project function to see where the points
    # appear in the camera image
    pts2 = cam.project(pts3)
    #
    # Visualize results. You do not need to change the code below, but
    # make sure you understand it so you can use it in the future to
    # perform your own visualizations.
    #
    # generate coordinates of a line segment running from the center
    # of the camera to 2 units in front of the camera along the z-axis
    # this is useful for visualizing what direction the camera is pointed
    # at in the plots below
    look = np.hstack((cam.t, cam.t + cam.R @ np.array([[0, 0, 2]]).T))
    # visualize the image of the points in the camera
    # draw a square [0,100]x[0,100] designating the box
    # we want the hemisphere to fall inside of
    fig = plt.figure()
    ax = fig.add_subplot(2, 2, 1)
    ax.plot(pts2[0, :], pts2[1, :], '.')
    ax.add_patch(patches.Rectangle((0, 0), 100, 100, color='r', fill=False))
    plt.grid()
    plt.axis('square')
    plt.title('camera projection')
    # overhead view (xz-plane) showing points, camera
    # position, and direction camera is pointed
    ax = fig.add_subplot(2, 2, 2)
    ax.plot(pts3[0, :], pts3[2, :], '.')
    ax.plot(cam.t[0], cam.t[2], 'ro')
    ax.plot(look[0, :], look[2, :], 'r')
    plt.axis('equal')
    plt.grid()
    plt.xlabel('x')
    plt.ylabel('z')
    plt.title('scene overhead view')
    # side view (yz-plane) showing points, camera
    # position, and direction camera is pointed
    ax = fig.add_subplot(2, 2, 3)
    ax.plot(pts3[2, :], pts3[1, :], '.')
    ax.plot(cam.t[2],cam.t[1],'ro')
    ax.plot(look[2,:],look[1,:],'r')
    plt.axis('equal')
    plt.grid()
    plt.xlabel('z')
    plt.ylabel('y')
    plt.title('scene side view')

    def triangulate(pts2L,camL,pts2R,camR):
        """
        Triangulate the set of points seen at location pts2L / pts2R in the
        corresponding pair of cameras. Return the 3D coordinates relative
        to the global coordinate system
        Parameters
        ----------
        pts2L : 2D numpy.array (dtype=float)
        Coordinates of N points stored in a array of shape (2,N) seen from c
        pts2R : 2D numpy.array (dtype=float)
        Coordinates of N points stored in a array of shape (2,N) seen from c
        camL : Camera
        The first "left" camera view
        camR : Camera
        The second "right" camera view
        Returns
        -------
        pts3 : 2D numpy.array (dtype=float)
        (3,N) array containing 3D coordinates of the points in global coordi
        """
        #
        # Your code goes here. I recommend adding assert statements to check th
        # sizes of the inputs and outputs to make sure they are correct
        #
        return pts3
        #
        # create a test scene with two cameras
        #
        # utility function to create a rotation matrix representing rotation
        # around y-axis by amount theta
    def roty(theta):
        st = np.sin(theta)
        ct = np.cos(theta)
        R = np.array([[ct,0,st],[0,1,0],[-st,0,ct]])
        return R

    #compute rotation angle so that the camera is centered on the sphere
    b = 5 #baseline between cameras
    d = 10 #distance to object
    theta = np.arctan((b/2)/d) #compute the rotation angle needed to point came
    tL = np.array([[-(b/2),0,0]]).T
    tR = np.array([[(b/2),0,0]]).T
    camL = Camera(f=100,c=np.array([[50,50]]).T,t=tL,R=roty(theta))
    camR = Camera(f=100,c=np.array([[50,50]]).T,t=tR,R=roty(-theta))
    #generate 3D points
    pts3 = generate_hemisphere(2,np.array([[0,0,d]]).T,500)
    #project into each camera
    pts2L = camL.project(pts3)
    pts2R = camR.project(pts3)
    #triangulate to recover 3d position
    pts3t = triangulate(pts2L,camL,pts2R,camR)
    #
    # visualize results
    #
    # generate coordinates of a line segment running from the center
    # of the camera to 3 units in front of the camera
    lookL = np.hstack((tL,tL+camL.R @ np.array([[0,0,2]]).T))
    lookR = np.hstack((tR,tR+camR.R @ np.array([[0,0,2]]).T))
    # visualize the left and right image overlaid
    fig = plt.figure()
    ax = fig.add_subplot(2,2,1)
    ax.plot(pts2L[0,:],pts2L[1,:],'b.')
    ax.plot(pts2R[0,:],pts2R[1,:],'r.')
    plt.axis('equal')
    plt.legend(('camL','camR'),loc=1)
    #visualize 3D layout of points, camera positions
    # and the direction the camera is pointing
    ax = fig.add_subplot(2,2,2,projection='3d')
    ax.plot(pts3[0,:],pts3[1,:],pts3[2,:],'.')
    ax.plot(tR[0],tR[1],tR[2],'ro')
    ax.plot(tL[0],tL[1],tL[2],'bo')
    ax.plot(lookL[0,:],lookL[1,:],lookL[2,:],'b')
    ax.plot(lookR[0,:],lookR[1,:],lookR[2,:],'r')

    visutils.set_axes_equal_3d(ax)
    visutils.label_axes(ax)
    plt.title('scene 3D view')
    # overhead view showing points, camera
    # positions, and direction camera is pointed
    ax = fig.add_subplot(2,2,3)
    ax.plot(pts3[0,:],pts3[2,:],'.')
    ax.plot(tL[0],tL[2],'bo')
    ax.plot(lookL[0,:],lookL[2,:],'b')
    ax.plot(tR[0],tR[2],'ro')
    ax.plot(lookR[0,:],lookR[2,:],'r')
    plt.axis('equal')
    plt.grid()
    plt.xlabel('x')
    plt.ylabel('z')
    plt.title('scene overhead view')
    # compare reconstruction
    ax = fig.add_subplot(2,2,4,projection='3d')
    ax.plot(pts3[0,:],pts3[1,:],pts3[2,:],'b.')
    ax.plot(pts3t[0,:],pts3t[1,:],pts3t[2,:],'ro',fillstyle='none')
    visutils.set_axes_equal_3d(ax)
    visutils.label_axes(ax)
    plt.title('reconstruction overlay')
    plt.legend(('true','reconstruction'),loc=4)

    #
    # triangulate the points again but modify camL so that the focal length
    # is 10% larger than the true value used to produce the 2d points
    #
    pts3t_badcalib = ...
    #
    # visualize reconstruction compared to noise-free reconstruction.
    # how do they differ from each other??
    #

    #
    # compute the average reconstruction error (distance between the true 3D loc
    # triangulated location, averaged over all the points) for both the perfect
    # and for the badly calibrated case (pts3t_badcalib) and print out the resul
    # in the notebook
    #