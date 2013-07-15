<?php

/**
 * @file
 * Make URL field absolute.
 */

$plugin = array(
  'form' => 'feeds_tamper_absolutize_plugin_absolutize_form',
  'callback' => 'feeds_tamper_absolutize_plugin_absolutize_callback',
  'name' => 'Make URL field absolute',
  'category' => 'HTML',
);

function feeds_tamper_absolutize_plugin_absolutize_form($importer, $element_key, $settings) {
  $form = array();
  $links = htmlentities('"/stuff/things" to "http://example.com/stuff/things"');
  $form['info'] = array(
    '#markup' => t('Make URL absolute. (i.e. !links).', array('!links' => $links)),
  );
  return $form;
}

function feeds_tamper_absolutize_plugin_absolutize_callback($result, $item_key, $element_key, &$field, $settings, $source) {
	module_load_include('inc', 'feeds_tamper', 'plugins/absolute_url.inc');
	$b = parse_url($result->link);
	$urls = array();
	$value = trim($field);
	_feeds_tamper_absolute_url($value, $urls, $b);
	$field = $urls[$value];
}
