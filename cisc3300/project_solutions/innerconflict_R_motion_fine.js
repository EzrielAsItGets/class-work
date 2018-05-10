function onClick( ) {
   texta = parseInt(document.getElementById("getvalue").value);


 image1 = document.createElement('img');
 image2 =document.querySelector('img');

 image1.src="bfly1.gif";
 image2.src="bfly2.gif";

   image1.style.width=50 +"px";
   image1.style.height=50 +"px";
   image1.style.top=470 +"px";
   image1.style.left=470 +"px";
   
   pos = 0;
  
 /*var id = setInterval(frame, 10);*/
var id = setInterval(frame, 50);

  function frame() {

  srcval = image1.src;
   image1.src = image2.src;
  image2.src = srcval;   

    if (pos == 350) {
      clearInterval(id);
    } 

       else {
   


  la = texta;
  incra = 150/la;
  console.log(la,"  la");
  for (i=1;i<=la; i++) {  
      divelement= document.createElement('div');
     ii = Math.floor(Math.random()*255);
     jj= Math.floor(Math.random()*255);
     kk= Math.floor(Math.random()*255);
     console.log( ii,"  ",jj,"   ",kk);
     divelement.style.backgroundColor = (ii,jj,kk);

       divelement.style.left=(400 + incra*(i -1)/2)+ 'px';
       divelement.style.top= (400 + incra*(i -1)/2) + 'px';
       divelement.style.height=(200 - (i-1)*incra) + 'px';
       divelement.style.width= (200  -(i-1)*incra) + 'px'; 

      /* divelement.style.left= "400px";
       divelement.style.top= "400px";
       divelement.style.height="200px";
       divelement.style.width= "200px"; */ 


      document.body.appendChild(divelement);  
      document.body.appendChild(image1);
                           }



    }

                             }
                      }
  button1=document.querySelector('button');
  button1.addEventListener('click',onClick);


   la = 10;
  incra = 100/la;

  console.log(la,"  la");

      for (i=1;i<=la; i++) {  
      divelement= document.createElement('div');
     ii = Math.floor(Math.random()*255);
     jj= Math.floor(Math.random()*255);
     kk= Math.floor(Math.random()*255);
     console.log( ii,"  ",jj,"   ",kk);
     divelement.style.backgroundColor = (ii,jj,kk);

       divelement.style.left=(400 + incra*(i -1)/2)+ 'px';
       divelement.style.top= (400 + incra*(i -1)/2) + 'px';
       divelement.style.height=(200 - (i-1)*incra) + 'px';
       divelement.style.width= (200  -(i-1)*incra) + 'px'; 

      /* divelement.style.left= "400px";
       divelement.style.top= "400px";
       divelement.style.height="200px";
       divelement.style.width= "200px"; */ 


      document.body.appendChild(divelement);  
                             
                          } 
  
       