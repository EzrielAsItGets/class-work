function searchFunction() {
  var term = $('#searchtext').val().trim().toLowerCase();
  if (term.length > 0) {
    var source = $('.main').text();
    var words = source.split(' ');
    var output = '';
    $.each(words, function(idx, word) {
      if (term === word.toLowerCase()) {
        output += '<span class="highlight">' + word + '</span> ';
      }
      else {
        output += word + ' ';
      }
    });
    $('div').html(output);
  }
}
