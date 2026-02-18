import xml.etree.ElementTree as ET
import sys
path = r'c:\Users\bensa\OneDrive\Documents\equipe_widget\equipe_widget.ui'
try:
    ET.parse(path)
    print('OK')
except Exception as e:
    print('PARSE_ERROR:', e)
    if hasattr(e, 'position'):
        print('POSITION:', e.position)
    sys.exit(1)
