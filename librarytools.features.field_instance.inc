<?php
/**
 * @file
 * librarytools.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function librarytools_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'librarytools_core_library-librarytools_core_library-field_core_css'.
  $field_instances['librarytools_core_library-librarytools_core_library-field_core_css'] = array(
    'bundle' => 'librarytools_core_library',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '\'css\': Like \'js\', an array of CSS elements passed to <a href="https://api.drupal.org/api/drupal/includes%21common.inc/function/drupal_add_css/7">drupal_add_css()</a>.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'librarytools_core_library',
    'field_name' => 'field_core_css',
    'label' => 'CSS',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 8,
      ),
      'type' => 'text_textarea',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'librarytools_core_library-librarytools_core_library-field_core_dependencies'.
  $field_instances['librarytools_core_library-librarytools_core_library-field_core_dependencies'] = array(
    'bundle' => 'librarytools_core_library',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'An array of libraries that are required for a library. Each element is an array listing the module and name of another library. Note that all dependencies for each dependent library will also be added when this library is added.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'librarytools_core_library',
    'field_name' => 'field_core_dependencies',
    'label' => 'Dependencies',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 8,
      ),
      'type' => 'text_textarea',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'librarytools_core_library-librarytools_core_library-field_core_js'.
  $field_instances['librarytools_core_library-librarytools_core_library-field_core_js'] = array(
    'bundle' => 'librarytools_core_library',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'An array of JavaScript elements; each element\'s key is used as $data argument, each element\'s value is used as $options array for <a href="https://api.drupal.org/api/drupal/includes%21common.inc/function/drupal_add_js/7">drupal_add_js()</a>. To add library-specific (not module-specific) JavaScript settings, the key may be skipped, the value must specify \'type\' => \'setting\', and the actual settings must be contained in a \'data\' element of the value.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'librarytools_core_library',
    'field_name' => 'field_core_js',
    'label' => 'JS',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 8,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'librarytools_core_library-librarytools_core_library-field_core_machine_name'.
  $field_instances['librarytools_core_library-librarytools_core_library-field_core_machine_name'] = array(
    'bundle' => 'librarytools_core_library',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The human readable name of the library.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'librarytools_core_library',
    'field_name' => 'field_core_machine_name',
    'label' => 'Machine name',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'librarytools_core_library-librarytools_core_library-field_core_version'.
  $field_instances['librarytools_core_library-librarytools_core_library-field_core_version'] = array(
    'bundle' => 'librarytools_core_library',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'A string specifying the version of the library; intentionally not a float because a version like "1.2.3" is not a valid float. Use PHP\'s <a href="http://php.net/version_compare">version_compare()</a> to compare different versions.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'librarytools_core_library',
    'field_name' => 'field_core_version',
    'label' => 'Version',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'librarytools_core_library-librarytools_core_library-field_core_website'.
  $field_instances['librarytools_core_library-librarytools_core_library-field_core_website'] = array(
    'bundle' => 'librarytools_core_library',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The URL of the library\'s web site.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_url',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'librarytools_core_library',
    'field_name' => 'field_core_website',
    'label' => 'Website',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 1,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('\'css\': Like \'js\', an array of CSS elements passed to <a href="https://api.drupal.org/api/drupal/includes%21common.inc/function/drupal_add_css/7">drupal_add_css()</a>.');
  t('A string specifying the version of the library; intentionally not a float because a version like "1.2.3" is not a valid float. Use PHP\'s <a href="http://php.net/version_compare">version_compare()</a> to compare different versions.');
  t('An array of JavaScript elements; each element\'s key is used as $data argument, each element\'s value is used as $options array for <a href="https://api.drupal.org/api/drupal/includes%21common.inc/function/drupal_add_js/7">drupal_add_js()</a>. To add library-specific (not module-specific) JavaScript settings, the key may be skipped, the value must specify \'type\' => \'setting\', and the actual settings must be contained in a \'data\' element of the value.');
  t('An array of libraries that are required for a library. Each element is an array listing the module and name of another library. Note that all dependencies for each dependent library will also be added when this library is added.');
  t('CSS');
  t('Dependencies');
  t('JS');
  t('Machine name');
  t('The URL of the library\'s web site.');
  t('The human readable name of the library.');
  t('Version');
  t('Website');

  return $field_instances;
}
