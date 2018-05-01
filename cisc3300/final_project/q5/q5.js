class button {

  constructor(container){
    this.container = document.querySelectorAll(container)[0];
    console.log(this.container)
    var items = this.container.children;

    var fnArr = [this.first, this.second, this.third]
    var ctr = 0;
    for(var child in items){

        if(items[parseInt(child)]){
          items[parseInt(child)].addEventListener('click', fnArr[ctr])
        }

        ctr += 1
    }

  }


  first(elem){
    var elem = this;
     elem.innerHTML= "<img src= 'gorilla.bmp' alt='Image' style='width:14em; height:14em;' />";
  }

  second(elem){
    var elem = this;
     elem.innerHTML= "<img src='City002.jpg' alt='Image' style='width:14em; height:14em;' />";

  }

  third(elem){
    var elem = this;
     elem.innerHTML= "<img src= 'City001.jpg' alt='Image' style='width:14em; height:14em;' />";
  }
}
