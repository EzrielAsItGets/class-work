function onClick() {
  image1 = document.querySelector('#img1');
  image2 =document.querySelector('#img2');
  /* image1=document.getElementById("img1");
  image2 =document.getElementById("img2");*/
  pos = 0;
  /*pos=image1.currentX;*/
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
      pos++;
      image1.style.top = pos + 'px';
      image1.style.left = pos + 'px';
      console.log(image1.style.top);
    }
  }

}

button1=document.querySelector('button');
button1.addEventListener('click',onClick);
