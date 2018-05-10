var xnew=0;
var ynew=0;
var xx =0;
var yy =0;
var th = 0 ;
var pos =0;
var x =0;
var y =0;

var delta = 5;

function  rot1(cx, cy, xx1, yy1, th){
/*console.log(cx,"  ",cy);*/
X0 = xx1;
Y0 = yy1;
/*console.log(th);*/
th0 = th / 180 * 3.14159;
/*console.log(th0);*/

/*x = (X0 - cx) * Cos(th0) - (Y0 - cy) * Sin(th0)
y = (X0 - cx) * Sin(th0) + (Y0 - cy) * Cos(th0)*/

xx = (X0 - cx) * Math.cos(th0) - (Y0 - cy) * Math.sin(th0);
yy = (X0 - cx) * Math.sin(th0) + (Y0 - cy) * Math.cos(th0);
xx = xx + cx;
yy = yy + cy;
/*console.log(xx,"  ",yy);*/
}
 
function onClick( ) {

 image1 = document.querySelector('#img1');
 image2 =document.querySelector('#img2');

 /* image1=document.getElementById("img1");
  image2 =document.getElementById("img2");*/

   
   /*pos = 0;*/
  /*pos=image1.currentX;*/

 /*var id = setInterval(frame, 10);*/
var id = setInterval(frame, 50);

 pos = 100;
  
      image1.style.top = pos + 'px'; 
      image1.style.left = pos + 'px'; 

  function frame() {

  srcval = image1.src;
   image1.src = image2.src;
  image2.src = srcval;   

    if ( th == 360 ) {
      clearInterval(id);
    } 
       else {
      th += 1;
      delta += 1;
      
     x = pos;
     y = pos;

      rot1(0,0, x, y, th);
      /*console.log(th, " ", xx,"   ",yy,"  ", Math.sqrt(xx*xx +yy*yy) );*/
     
      /*xx = xx + pos;
      yy = yy + pos;*/

      image1.style.top =  yy+200 +delta+'px'; 
      image1.style.left =  xx+200+delta+ 'px';
      image1.classList.remove('hidden');



      rot1(0,0, x, y, -th);
      image2.style.top =  yy+200 +delta+'px'; 
      image2.style.left =  xx+800-delta+ 'px';
      image2.classList.remove('hidden');


     /* image1.style.top =  yy +'px'; 
      image1.style.left =  xx + 'px';
     pos += 1; */
     console.log(image1.style.top);
    }

                             }
                      }
  button1=document.querySelector('button');
  button1.addEventListener('click',onClick);