var xnew=0;
var ynew=0;
var xx =0;
var yy =0;
var th = 0 ;

function  rot1(cx, cy, xx1, yy1, th) {
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
  pos = 100;
  image1.style.top = pos + 'px';
  image1.style.left = pos + 'px';
  var id = setInterval(frame, 10);

  function frame() {
    srcval = image1.src;
    image1.src = image2.src;
    image2.src = srcval;

    if (th == 360) {
      clearInterval(id);
    }
    else {
      th+= 1;
      /* console.log(image1.style.top);*/
      x = pos;
      y = pos;
      rot1(0,0, x, y, th);
      console.log(th, " ", xx,"   ",yy,"  ", Math.sqrt(xx*xx +yy*yy) );
      image1.style.top =  yy+200 +'px';
      image1.style.left =  xx+200+ 'px';
      console.log(th, " ", image1.style.left,"   ",image1.style.top,"  " );
    }

  }
}

  button1=document.querySelector('button');
  button1.addEventListener('click',onClick);
