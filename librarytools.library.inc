<?php

/**
 * @file
 * Provides tools related to library functionality provided by Drupal core.
 */

/**
 * Helper function to generate content for cells of libraries table.
 */
function _librarytools_hook_library_table_cells($library_name, $library, $libraries, $module, $cell) {
  $output = '';
  switch ($cell) {
    case 'name':
      $path = str_replace('%librarytools_library_info', $module->name . ':' . $library_name, LIBRARYTOOLS_LIBRARY_INFO);
      $output = theme('librarytools_title', array('title' => l($library['title'], $path)));
      break;

    case 'provider':
      $output = $module->name;
      break;

    case 'version':
      $output = $library['version'];
      break;

    case 'dependencies':
      $dependencies = array();
      foreach ($library['dependencies'] as $dependency) {
        foreach ($dependency as $dependency_name) {
          if (!empty($library) && $dependency_name != 'system') {
            if (array_key_exists($dependency_name, $libraries)) {
              $status = t('present');
              $class_name = 'admin-enabled';
            }
            else {
              $status = t('missing');
              $class_name = 'admin-disabled';
            }

            $variables = array(
              'class_name' => $class_name,
              'dependency_name' => $dependency_name,
              'status' => $status,
            );
            $dependencies[] = theme('librarytools_dependency', $variables);
          }
        }

      }

      $output = theme('librarytools_dependencies', array('dependencies' => $dependencies));
      break;

    case 'files':
      $items = array();
      $type_labels = array(
        'css' => theme('librarytools_title', array('title' => t('CSS'))),
        'js' => theme('librarytools_title', array('title' => t('Javascript'))),
      );

      foreach ($library as $type => $value) {
        if (array_key_exists($type, $type_labels)) {
          if (!empty($library[$type])) {
            $items[$type]['data'] = $type_labels[$type];
          }
          foreach ($library[$type] as $path => $info) {
            $items[$type]['children'][] = pathinfo($path, PATHINFO_BASENAME);
          }
        }
      }

      $output = theme('item_list', array('items' => $items));
      break;

    case 'path':
      $output = pathinfo($module->filename, PATHINFO_DIRNAME);
      break;

    case 'links':
      foreach ($library as $label => $value) {
        if ($label === 'website') {
          $output = l(t('Website'), $value);
          break;
        }
      }
      break;
  }

  return $output;
}

/**
 * Helper function to list hook_library() libraries.
 *
 * (I.e. libraries provided using core library function).
 */
function _librarytools_hook_library_libraries() {
  $result = db_query("SELECT name, filename FROM {system} WHERE type = 'module' AND status = 1");

  // Make the table header.
  $header = array(
    'name' => array(
      'data' => t('Library name'),
      'sort' => 'asc',
    ),
    'provider' => array(
      'data' => t('Library provider'),
    ),
    'version' => array(
      'data' => t('Library version'),
    ),
    'dependencies' => array(
      'data' => t('Dependencies'),
    ),
    'files' => array(
      'data' => t('Files'),
    ),
    'path' => array(
      'data' => t('Path') . '<sup>' . l('1', drupal_get_path_alias(), array('fragment' => 'library1')) . '</sup>',
    ),
    'links' => array(
      'data' => t('Links'),
    ),
  );

  $rows = array();

  foreach ($result as $module) {
    if ($libraries = drupal_get_library($module->name)) {
      foreach ($libraries as $library_name => $library) {
        $rows[] = array(
          _librarytools_hook_library_table_cells($library_name, $library, $libraries, $module, 'name'),
          _librarytools_hook_library_table_cells($library_name, $library, $libraries, $module, 'provider'),
          _librarytools_hook_library_table_cells($library_name, $library, $libraries, $module, 'version'),
          _librarytools_hook_library_table_cells($library_name, $library, $libraries, $module, 'dependencies'),
          _librarytools_hook_library_table_cells($library_name, $library, $libraries, $module, 'files'),
          _librarytools_hook_library_table_cells($library_name, $library, $libraries, $module, 'path'),
          _librarytools_hook_library_table_cells($library_name, $library, $libraries, $module, 'links'),
        );
      }
    }

    // Apologize if there are no libraries :)
    $empty = t('No libraries were found.');
    $caption = t('Summary of libraries declared with <code><a href="https://api.drupal.org/api/drupal/modules%21system%21system.api.php/function/hook_library/7">hook_library()</a></code> implementations.');
  }

  $variables = array(
    'header' => $header,
    'rows' => $rows,
    'empty' => $empty,
    'caption' => $caption,
    'attributes' => array(
      'id' => 'library-tools-hook-library-summary',
    ),
  );

  $output = theme('table', $variables);
  $output .= theme('item_list', array(
    'items' => array(
      array(
        'data' => t('Individual library files may be contained in a subdirectory at this location.'),
        'id' => 'library1',
      ),
    ),
    'type' => 'ol',
  ));

  return $output;
}
