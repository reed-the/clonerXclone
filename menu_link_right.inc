<?php
/**
 * category_menu Class
 * 
 * This class sets up a custom widget for the wpturbo plugin
 * 
 * @package WPTurbo
 */
class menu_link_right extends WP_Widget {

	/**
	 * Initialize the widget
	 *
	 * @return void
	 */
	function __construct() {
		parent::__construct(
			'menu_link_right',
			esc_html__( 'Header - menu link', 'wpturbo' ),
			[ 'description' => esc_html__( 'Do not delete this plugin', 'wpturbo' ), ]
		);
	}

	/**
	 * Widget Fields array
	 * 
	 * @var array $widget_fields Array of fields.
	 */
	private $widget_fields = [
		[
			'label' => 'Link text',
			'id' => 'name',
			'default' => 'My link',
			'type' => 'text',
		],
		[
			'label' => 'URL',
			'id' => 'url',
			'default' => '#',
			'type' => 'url',
		],
		[
			'label' => 'HOT?',
			'id' => 'hot',
			'type' => 'checkbox',
		],        
	];

	/**
	 * This function generates the content that will be displayed, which is determined by the user's input.
	 *
	 * @param array $args Array of arguments.
	 * @param array $instance Array of instance.
	 * 
	 * @return void
	 */
	public function widget( array $args, array $instance ) : void {
		// Before and after widget  is set by the theme.
		//echo $args['before_widget'];



        // Now, output the generated fields
		echo '<div class="bottom-header__faq">

		'.$args['before_widget'].'
        '.$args['after_widget'].'
        
                        '.( ($instance['hot']  > 0) ? '<div class="label">hot</div>' : '' ).'
						<a href="' . $instance['url'] . '">' . $instance['name'] . '</a>
        
        			</div>
					';

		//echo $args['after_widget'];
	}


	/**
	 * Generates the widget fields.
	 *
	 * @param array $instance The array of options.
	 * 
	 * @return void
	 */
	public function field_generator( array $instance ) : void {
		$output = '';
		foreach ( $this->widget_fields as $widget_field ) {
			$default = '';
			if ( isset($widget_field['default']) ) {
				$default = $widget_field['default'];
			}

			$widget_value = ! empty( $instance[$widget_field['id']] ) ? $instance[$widget_field['id']] : esc_html__( $default, 'textdomain' );
			switch ( $widget_field['type'] ) {
				case 'checkbox':
					$output .= '<p>';
					$output .= '<input class="checkbox" type="checkbox" '.checked( $widget_value, true, false ).' id="'.esc_attr( $this->get_field_id( $widget_field['id'] ) ).'" name="'.esc_attr( $this->get_field_name( $widget_field['id'] ) ).'" value="1">';
					$output .= '<label for="'.esc_attr( $this->get_field_id( $widget_field['id'] ) ).'">'.esc_attr( $widget_field['label'], 'domtest' ).'</label>';
					$output .= '</p>';
					break;
				default:
					$output .= '<p>';
					$output .= '<label for="'.esc_attr( $this->get_field_id( $widget_field['id'] ) ).'">'.esc_attr( $widget_field['label'], 'textdomain' ).':</label> ';
					$output .= '<input class="widefat" id="'.esc_attr( $this->get_field_id( $widget_field['id'] ) ).'" name="'.esc_attr( $this->get_field_name( $widget_field['id'] ) ).'" type="'.$widget_field['type'].'" value="'.esc_attr( $widget_value ).'">';
					$output .= '</p>';
			}
		}
		echo $output;
	}

	/**
	 * Outputs the options form on admin
	 *
	 * @param array $instance The array of options
	 * 
	 * @return void
	 */
	public function form( array $instance ) : void {
		$this->field_generator( $instance );
	}

	/**
	 * Processes widget options to be saved
	 *
	 * @param array $new_instance The new array of options
	 * @param array $old_instance The old array of options
	 * 
	 * @return array $instance The updated array of options
	 */
	public function update( array $new_instance, array $old_instance ): array {
		$instance = [];
		$instance['title'] = ( ! empty( $new_instance['title'] ) ) ? strip_tags( $new_instance['title'] ) : '';
		foreach ( $this->widget_fields as $widget_field ) {
			switch ( $widget_field['type'] ) {
            
				default:
					$instance[$widget_field['id']] = ( ! empty( $new_instance[$widget_field['id']] ) ) ? strip_tags( $new_instance[$widget_field['id']] ) : '';
			}
		}
		return $instance;
	}
}

/**
 * Registers menu_link_right widget
 *
 * @return void
 */
function register_menu_link_right_widget() : void {
	register_widget( 'menu_link_right' );
}
add_action( 'widgets_init', 'register_menu_link_right_widget' );

