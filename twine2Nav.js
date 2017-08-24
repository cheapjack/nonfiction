//wait a second and select the first tw-link on the page
jQuery(document).ready(function() {
  setTimeout(function(){jQuery('tw-expression tw-link:first').focus()}, 1000);
});

//select tw-story node
var target = document.getElementsByTagName("tw-story")[0];

// create an observer instance, get it to execute a function whenever tw-story changes (i.e. when the user interacts)
var observer = new MutationObserver(function(mutations) {
  setTimeout(function(){jQuery('tw-expression tw-link:first').focus()}, 1000)
});

// configuration of the observer:
var config = { attributes: true, childList: true, characterData: true };

// pass in the target node, as well as the observer options
observer.observe(target, config);

//bind left and right keypresses to link navigation
jQuery(document).keydown(function(e){
	if (e.which == 38) {
    jQuery('tw-link:focus').parent('tw-expression').prev().find('tw-link').focus();
  }
  else if (e.which == 40) {
    jQuery('tw-link:focus').parent('tw-expression').next().find('tw-link').focus();
  }
// extra code to trigger menu, note change of order and handler :)
  else if (e.shiftKey && e.which == 77){
    window.location.href = "../InF.html";
  }

});
