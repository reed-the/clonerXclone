<?php
/*
* Plugin Name: Special Widgets
* Description: DO NOT DELETE THIS PLUGIN. Theme-required 
* Version: 1.0.0
* Author: WPTurbo
* Author URI: https://wpturbo.dev
*/

/**
 * wpturbo_My_Custom_Widget Class
 * 
 * This class sets up a custom widget for the wpturbo plugin
 * 
 * @package WPTurbo
 */


require_once(ABSPATH . 'wp-content/plugins/'.'category_menu.inc');
require_once(ABSPATH . 'wp-content/plugins/'.'menu_link_right.inc');
/*
function reload_wpf_plugin() {

 if (class_exists('WPF'))
 {
  remove_action( 'woocommerce_before_main_content', array( WPF::get_instance(), 'result_container' ), 100 );
  remove_action( 'woocommerce_after_main_content', array( WPF::get_instance(), 'close_div' ), 1 );
 }
}
 
 

add_action('plugins_loaded', 'reload_wpf_plugin');
*/


function filter_some_block($block_content, $block)
{
       //print_r($block);
       /*
Array
(
    [blockName] => core/paragraph
    [attrs] => Array
        (
        )

    [innerBlocks] => Array
        (
        )

    [innerHTML] => 
<p>test</p>

    [innerContent] => Array
        (
            [0] => 
<p>test</p>

        )

)       
       */
       /*
if ($block['blockName'] === 'core/heading') {

        return '<div class="my-ad"></div>' . $block_content;

    }
    
    
           
       */

 
        return $block_content;


}

add_filter( 'render_block', 'filter_some_block', 10, 2 );


/*
add_filter('render_block_core/heading', 'hide_images', 10, 2);

function echo_1(){
	echo 'Hello';
}

// привяжем функцию к хуку
add_action( 'my_hook', 'echo_1' );

*/
