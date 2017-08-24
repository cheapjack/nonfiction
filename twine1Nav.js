setTimeout(function() {
  var internalLinks = document.getElementsByClassName('internalLink');
  for (var i = 0; i < internalLinks.length; i ++) {
	  internalLinks[i].href = "#";
  }
  internalLinks[0].focus();
  var target = document.getElementById("passages");
  var observer = new MutationObserver(function(mutations) {
    console.log("Change");
    setTimeout(function() {
    var internalLinks = document.getElementsByClassName('internalLink');
    for (var i = 0; i < internalLinks.length; i ++) {
  	  internalLinks[i].href = "#";
    }
    internalLinks[0].focus();
  }, 1000);
  });
  var config = { attributes: true, childList: true, characterData: true };
  observer.observe(target, config);
  function keySelectOption(inputs) {
    for (var i=0; i<inputs.length; i++) {
      document.onkeydown = function(e) {
      var option = document.activeElement;
      if (e.keyCode==40) {
        var node = option.nextSibling;
        while (node) {
          if (node.tagName=='A') {
            node.focus();
            break;
          }
          node = node.nextSibling;
        }
      }
      else if (e.keyCode==38) {
        var node = option.previousSibling;
        while (node) {
          if (node.tagName=='A') {
            node.focus();
            break;
          }
          node = node.previousSibling;
        }
      }
// extra code to trigger menu
      else if (e.code == "KeyM" && e.shiftKey){
        window.location.href = "InF.html";
	};
    };
  };
}
keySelectOption(document.getElementsByTagName('a'));
}, 1000);
