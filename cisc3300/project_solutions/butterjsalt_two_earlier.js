
function onClick( ) {

 image1 = document.querySelector('#img1');
 image2 =document.querySelector('#img2');

 /* image1=document.getElementById("img1");
  image2 =document.getElementById("img2");*/

   
   pos = 0;
   pos1 =0;
  /*pos=image1.currentX;*/

 /*var id = setInterval(frame, 10);*/
var id = setInterval(frame, 50);

  function frame() {

  srcval = image1.src;
   image1.src = image2.src;
  image2.src = srcval;   

    if (pos == 500) {
      clearInterval(id);
    } 

       
       else {
      var ind =1;
      pos++; 

      if  (pos <= 100) { 
      image1.style.top = 300 + 'px'; 
      image1.style.left =200+ pos + 'px'; 
     console.log(image1.style.top);

    image2.style.top = 300 + 'px'; 
      image2.style.left = 600 - pos + 'px'; 
     console.log(image2.style.top);                                           }

     if  (pos  > 100 )    { 
      pos1++
      image1.style.top = 300 + 'px'; 
      image1.style.left = 300 -pos1 + 'px'; 
     console.log(image1.style.top);

      image2.style.top = 300 + 'px'; 
      image2.style.left = 500 + pos1 + 'px'; 
     console.log(image2.style.top);                                           }


    }

                             }
                      }
  button1=document.querySelector('button');
  button1.addEventListener('click',onClick);